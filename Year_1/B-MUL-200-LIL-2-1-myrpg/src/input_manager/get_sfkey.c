/*
** EPITECH PROJECT, 2021
** get_sfkey.c
** File description:
** get sfKey
*/

#include "my.h"
#include "framing_engine.h"

sfKeyCode int_to_key(int value)
{
    sfKeyCode key[76] = {sfKeyA, sfKeyB, sfKeyC, sfKeyD, sfKeyE, sfKeyF, sfKeyG,
                        sfKeyH, sfKeyI, sfKeyJ, sfKeyK, sfKeyL, sfKeyM, sfKeyN,
                        sfKeyO, sfKeyP, sfKeyQ, sfKeyR, sfKeyS, sfKeyT, sfKeyU,
                        sfKeyV, sfKeyW, sfKeyX, sfKeyY, sfKeyZ, sfKeyNum0,
                        sfKeyNum1, sfKeyNum2, sfKeyNum3, sfKeyNum4, sfKeyNum5,
                        sfKeyNum6, sfKeyNum7, sfKeyNum8, sfKeyNum9, sfKeyEscape,
                        sfKeyLControl, sfKeyLShift, sfKeyLAlt, sfKeyLSystem,
                        sfKeyRControl, sfKeyRShift, sfKeyRAlt, sfKeyRSystem,
                        sfKeyMenu, sfKeyLBracket, sfKeyRBracket, sfKeySemicolon,
                        sfKeyComma, sfKeyPeriod, sfKeyQuote, sfKeySlash,
                        sfKeyBackslash, sfKeyTilde, sfKeyEqual, sfKeyHyphen,
                        sfKeySpace, sfKeyEnter, sfKeyBackspace, sfKeyTab,
                        sfKeyPageUp, sfKeyPageDown, sfKeyEnd, sfKeyHome,
                        sfKeyInsert, sfKeyDelete, sfKeyAdd, sfKeySubtract,
                        sfKeyMultiply, sfKeyDivide, sfKeyLeft, sfKeyRight,
                        sfKeyUp, sfKeyDown, sfKeyUnknown};

    if (value > 75 || value < 0)
        return (sfKeyUnknown);
    return (key[value]);
}

sfKeyCode get_sfkey(framing *lvl)
{
    sfKeyCode key[76] = {sfKeyA, sfKeyB, sfKeyC, sfKeyD, sfKeyE, sfKeyF, sfKeyG,
                        sfKeyH, sfKeyI, sfKeyJ, sfKeyK, sfKeyL, sfKeyM, sfKeyN,
                        sfKeyO, sfKeyP, sfKeyQ, sfKeyR, sfKeyS, sfKeyT, sfKeyU,
                        sfKeyV, sfKeyW, sfKeyX, sfKeyY, sfKeyZ, sfKeyNum0,
                        sfKeyNum1, sfKeyNum2, sfKeyNum3, sfKeyNum4, sfKeyNum5,
                        sfKeyNum6, sfKeyNum7, sfKeyNum8, sfKeyNum9, sfKeyEscape,
                        sfKeyLControl, sfKeyLShift, sfKeyLAlt, sfKeyLSystem,
                        sfKeyRControl, sfKeyRShift, sfKeyRAlt, sfKeyRSystem,
                        sfKeyMenu, sfKeyLBracket, sfKeyRBracket, sfKeySemicolon,
                        sfKeyComma, sfKeyPeriod, sfKeyQuote, sfKeySlash,
                        sfKeyBackslash, sfKeyTilde, sfKeyEqual, sfKeyHyphen,
                        sfKeySpace, sfKeyEnter, sfKeyBackspace, sfKeyTab,
                        sfKeyPageUp, sfKeyPageDown, sfKeyEnd, sfKeyHome,
                        sfKeyInsert, sfKeyDelete, sfKeyAdd, sfKeySubtract,
                        sfKeyMultiply, sfKeyDivide, sfKeyLeft, sfKeyRight,
                        sfKeyUp, sfKeyDown, sfKeyUnknown};

    for (lvl->key = 0; sfKeyboard_isKeyPressed(key[lvl->key]) == false &&
        lvl->key < 75; lvl->key++);
    return (key[lvl->key]);
}
