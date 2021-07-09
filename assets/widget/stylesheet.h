#ifndef STYLESHEET_H
#define STYLESHEET_H

#include <QFile>
#include <QTextStream>

struct StyleSheet
{
    struct Qss
    {
        static inline QString Button=":/assets/stylesheet/button.qss";
        static inline QString LineEdit=":/assets/stylesheet/lineedit.qss";
        static inline QString InputSinner=":/assets/stylesheet/inputspinner.qss";
        static inline QString CheckBox=":/assets/stylesheet/checkbox.qss";
        static inline QString MessageBox=":/assets/stylesheet/messagebox.qss";
        static inline QString Modal=":/assets/stylesheet/modal.qss";
        static inline QString ComboBox=":/assets/stylesheet/combobox.qss";
    };


    static QString loadStyleSheet(const QString resource)
    {
        QFile f(resource);
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        return ts.readAll();
    }
};



#endif // STYLESHEET_H
