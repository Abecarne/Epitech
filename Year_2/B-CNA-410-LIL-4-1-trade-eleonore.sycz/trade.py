#!/usr/bin/python3
# -*- coding: iso-8859-1 -*
""" Python starter bot for the Crypto Trader games, from ex-Riddles.io """
__version__ = "1.0"

"""
    ---    <-- high     {botState.charts["USDT_BTC"].highs[-1]}
     |
     |
     |
    ---    <-- open     {botState.charts["USDT_BTC"].opens[-1]}
    | |
    | |
    | |
    | |
    | |
    ---    <-- close    {botState.charts["USDT_BTC"].closes[-1]}
     |
     |
    ---    <-- low      {botState.charts["USDT_BTC"].lows[-1]}
"""

import sys
import numpy as np
import pandas as pd

# fill a csv file with values in tab
def fill_csv(file_name, values):
    with open(file_name, 'w') as f:
        for value in values:
            f.write(str(value) + "\n")

class Bot:
    def __init__(self):
        self.botState = BotState()
        self.calculs = Calculs()
        self.start = False
        self.avg200IsSup = True
        self.avg50IsSup = True
        self.avg20IsSup = True
        self.blgUp = []
        self.blgDown = []
        self.avg200 = []
        self.avg50 = []
        self.avg20 = []
        self.avg7 = []

    def run(self):
        while True:
            reading = input()
            # print(f'input = {reading}', file=sys.stderr)
            if len(reading) == 0:
                continue
            self.parse(reading)

    def updateDatas(self):
        self.calculs.middleCandle.append((self.botState.charts["USDT_BTC"].closes[-1] + self.botState.charts["USDT_BTC"].opens[-1]) / 2)
        if self.start == False:
            self.calculs.getMidCandle(self.botState.charts["USDT_BTC"].opens, self.botState.charts["USDT_BTC"].closes)
            self.avg200 = self.calculs.getMovingAverage(self.calculs.middleCandle, 200)
            self.avg50 = self.calculs.getMovingAverage(self.calculs.middleCandle, 50)
            if self.avg200[-1] < self.avg50[-1]:
                self.avg200IsSup = False
            else:
                self.avg200IsSup = True
            self.avg20 = self.calculs.getMovingAverage(self.calculs.middleCandle, 20)
            if self.avg50[-1] < self.avg20[-1]:
                self.avg50IsSup = False
            else:
                self.avg50IsSup = True
            self.avg7 = self.calculs.getMovingAverage(self.calculs.middleCandle, 7)
            if self.avg20[-1] < self.avg7[-1]:
                self.avg20IsSup = False
            else:
                self.avg20IsSup = True
            self.calculs.getRelativeEvolution(self.calculs.middleCandle, 20)
            if self.calculs.evolution[-1] > 0:
                self.calculs.positive_evolution = True
            else:
                self.calculs.positive_evolution = False
            self.start = True
        else:
            self.calculs.middleCandle.append((self.botState.charts["USDT_BTC"].opens[-1] + self.botState.charts["USDT_BTC"].closes[-1]) / 2)
            self.avg200 = self.calculs.getMovingAverage(self.calculs.middleCandle, 200)
            self.avg50 = self.calculs.getMovingAverage(self.calculs.middleCandle, 50)
            self.avg20 = self.calculs.getMovingAverage(self.calculs.middleCandle, 20)
            self.avg7 = self.calculs.getMovingAverage(self.calculs.middleCandle, 7)
            self.calculs.getRelativeEvolution(self.calculs.middleCandle, 20)

    def parse(self, info: str):
        tmp = info.split(" ")
        if tmp[0] == "settings":
            self.botState.update_settings(tmp[1], tmp[2])
        elif tmp[0] == "update":
            if tmp[1] == "game":
                self.botState.update_game(tmp[2], tmp[3])
        elif tmp[0] == "action":
            self.updateDatas()
            dollars = self.botState.stacks["USDT"]
            bitcoin = self.botState.stacks["BTC"]
            current_closing_price = self.botState.charts["USDT_BTC"].closes[-1]
            affordable = dollars / current_closing_price
            evolution = self.calculs.evolution
            isPositiveEvoluton = self.calculs.positive_evolution

            print(f'My stacks are {dollars}. The current closing price is {current_closing_price}. So I can afford {affordable}', file=sys.stderr)
            
            if evolution[-1] < 0:
                if isPositiveEvoluton == True:
                    self.calculs.positive_evolution = False
                    bitcoin = self.botState.stacks["BTC"]
                    if bitcoin * current_closing_price < 1:
                        print("no_moves", flush=True)
                    else:
                        print("################### Sell #########################", file=sys.stderr)
                        print(f"sell USDT_BTC {0.8 * bitcoin}", flush=True)
                else:
                    print("no_moves", flush=True)
            elif self.avg200[-1] < self.avg50[-1]:
                if (self.avg200IsSup == True):
                    self.avg200IsSup = False
                    if bitcoin * current_closing_price < 1:
                        print("no_moves", flush=True)
                    else:
                        print("################### Sell #########################", file=sys.stderr)
                        print(f"sell USDT_BTC {0.8 * bitcoin}", flush=True)
                else:
                    print("no_moves", flush=True)
            elif self.avg50[-1] < self.avg20[-1]:
                if (self.avg50IsSup == True):
                    self.avg50IsSup = False
                    if bitcoin * current_closing_price < 1:
                        print("no_moves", flush=True)
                    else:
                        print("################### Sell #########################", file=sys.stderr)
                        print(f"sell USDT_BTC {0.6 * bitcoin}", flush=True)
                else:
                    print("no_moves", flush=True)
            elif self.avg20[-1] >= self.avg7[-1]:
                if (self.avg20IsSup == True):
                    self.avg20IsSup = False
                    if bitcoin * current_closing_price < 1:
                        print("no_moves", flush=True)
                    else:
                        print("################### Sell #########################", file=sys.stderr)
                        print(f"sell USDT_BTC {0.5 * bitcoin}", flush=True)
                else:
                    print("no_moves", flush=True)
            else:
                if isPositiveEvoluton == False:
                    self.calculs.positive_evolution = True
                    if dollars > 10:
                        print("##################### Buy #######################", file=sys.stderr)
                        print(f"buy USDT_BTC {0.6 * affordable}", flush=True)
                    else:
                        print("no_moves", flush=True)
                elif (self.avg200IsSup == False):
                    self.avg200IsSup = True
                    if dollars > 10:
                        print("##################### Buy #######################", file=sys.stderr)
                        print(f"buy USDT_BTC {0.5 * affordable}", flush=True)
                    else:
                        print("no_moves", flush=True)
                elif (self.avg50IsSup == False):
                    self.avg50IsSup = True
                    if dollars > 10:
                        print("##################### Buy #######################", file=sys.stderr)
                        print(f"buy USDT_BTC {0.3 * affordable}", flush=True)
                    else:
                        print("no_moves", flush=True)
                elif (self.avg20IsSup == False):
                    self.avg20IsSup = True
                    if dollars > 10:
                        print("##################### Buy #######################", file=sys.stderr)
                        print(f"buy USDT_BTC {0.2 * affordable}", flush=True)
                    else:
                        print("no_moves", flush=True)
                else:
                    print("no_moves", flush=True)

class Candle:
    def __init__(self, format, intel):
        tmp = intel.split(",")
        for (i, key) in enumerate(format):
            value = tmp[i]
            if key == "pair":
                self.pair = value
            elif key == "date":
                self.date = int(value)
            elif key == "high":
                self.high = float(value)
            elif key == "low":
                self.low = float(value)
            elif key == "open":
                self.open = float(value)
            elif key == "close":
                self.close = float(value)
            elif key == "volume":
                self.volume = float(value)

    def __repr__(self):
        return str(self.pair) + str(self.date) + str(self.close) + str(self.volume)


class Chart:
    def __init__(self):
        self.dates = []
        self.opens = []
        self.highs = []
        self.lows = []
        self.closes = []
        self.volumes = []
        self.indicators = {}

    def add_candle(self, candle: Candle):
        self.dates.append(candle.date)
        self.opens.append(candle.open)
        self.highs.append(candle.high)
        self.lows.append(candle.low)
        self.closes.append(candle.close)
        self.volumes.append(candle.volume)


class BotState:
    def __init__(self):
        self.nbCandles = 0
        self.timeBank = 0
        self.maxTimeBank = 0
        self.timePerMove = 1
        self.candleInterval = 1
        self.candleFormat = []
        self.candlesTotal = 0
        self.candlesGiven = 0
        self.initialStack = 0
        self.transactionFee = 0.1
        self.date = 0
        self.stacks = dict()
        self.charts = dict()

    def update_chart(self, pair: str, new_candle_str: str):
        if not (pair in self.charts):
            self.charts[pair] = Chart()
        new_candle_obj = Candle(self.candleFormat, new_candle_str)
        self.charts[pair].add_candle(new_candle_obj)

    def update_stack(self, key: str, value: float):
        self.stacks[key] = value

    def update_settings(self, key: str, value: str):
        if key == "timebank":
            self.maxTimeBank = int(value)
            self.timeBank = int(value)
        elif key == "time_per_move":
            self.timePerMove = int(value)
        elif key == "candle_interval":
            self.candleInterval = int(value)
        elif key == "candle_format":
            self.candleFormat = value.split(",")
        elif key == "candles_total":
            self.candlesTotal = int(value)
        elif key == "candles_given":
            self.candlesGiven = int(value)
        elif key == "initial_stack":
            self.initialStack = int(value)
        elif key == "transaction_fee_percent":
            self.transactionFee = float(value)

    def update_game(self, key: str, value: str):
        if key == "next_candles":
            new_candles = value.split(";")
            self.date = int(new_candles[0].split(",")[1])
            for candle_str in new_candles:
                candle_infos = candle_str.strip().split(",")
                self.update_chart(candle_infos[0], candle_str)
            self.nbCandles += 1
        elif key == "stacks":
            new_stacks = value.split(",")
            for stack_str in new_stacks:
                stack_infos = stack_str.strip().split(":")
                self.update_stack(stack_infos[0], float(stack_infos[1]))


class Calculs:
    def __init__(self):
        self.evolution = []
        self.bollingerUp = []
        self.middleCandle = []
        self.movingAverage = []
        self.bollingerDown = []
        self.standardDeviation = []
        self.positive_evolution = True

    def getRelativeEvolution(self, list_data, period):
        if float(list_data[len(list_data) - (int(period) + 1)]) == 0:
            self.evolution.append(0)
        r = (float(list_data[len(list_data) - 1]) - float(list_data[len(list_data) - (int(period) + 1)])) / (float(list_data[len(list_data) - (int(period) + 1)]))
        self.evolution.append(r * 100)

    def getMidCandle(self, open, close):
        for i in range(len(open)):
            self.middleCandle.append((open[i] + close[i]) / 2)

    def getMovingAverage(self, tab, period):
        numbers_series = pd.Series(tab)
        windows = numbers_series.rolling(period)
        moving_averages = windows.mean()

        moving_averages_list = moving_averages.tolist()
        without_nans = moving_averages_list[period - 1:]

        return without_nans

    def getStandardDeviation(self, tab):
        self.standardDeviation = np.std(tab)

    def getBollingerUp(self, tab):
        for i in tab:
            self.bollingerUp.append(i + 2 * self.standardDeviation)

    def getBollingerDown(self, tab):
        for i in tab:
            self.bollingerDown.append(i - 2 * self.standardDeviation)

    def getLastN(self, tab, n):
        return tab[-n:]

if __name__ == "__main__":
    mybot = Bot()
    mybot.run()
