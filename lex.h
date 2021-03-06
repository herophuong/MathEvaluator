#ifndef LEX_H
#define LEX_H
#include <QObject>
#include "big_num.h"

//LEXICAL ANALYSE
class lex : public QObject{
    Q_OBJECT
private:
    enum TYPE {no, op};
    class lex_sequence {
    public:
        big_num number;
        char math_op;
        TYPE element;
    };
    vector<lex_sequence> lexed_result;
    vector<lex_sequence> lex_analyse(const string& str);
    big_num result;

    void lex_validate(vector<lex_sequence> &lx);
    void lex_standardize(vector<lex_sequence> &lx);
    void lex_check(vector<lex_sequence> &lx);
    void display_error(int error_code);
public:
    lex();
    string input;
    void set(const string& str);
    void evaluate();
    QString standardized();
    QString standardized(vector<lex_sequence> result);

    void excute();
signals:
    void error(QString);
    void result_str(QString);
    void success();
};

#endif // LEX_H
