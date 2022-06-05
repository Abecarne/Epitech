/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

class Parser {
    public:
        Parser();
        Parser(char *filename);
        ~Parser();
        void setFileContent(char *filename);
        void setInfos(void);

        std::vector<std::pair<std::string, std::string>> getTabInputs(void);
        std::vector<std::pair<std::string, std::string>> getTabOutputs(void);
        std::vector<std::pair<std::string, std::string>> getTabLinks(void);
        std::vector<std::pair<std::string, std::string>> getTabNames(void);

    private:
        std::string _content;
        std::vector<std::pair<std::string, std::string>> _inputs;
        std::vector<std::pair<std::string, std::string>> _outputs;
        std::vector<std::pair<std::string, std::string>> _links;
        std::vector<std::pair<std::string, std::string>> _names;

};

#endif /* !PARSER_HPP_ */
