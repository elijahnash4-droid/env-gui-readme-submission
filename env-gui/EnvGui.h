#ifndef ENVGUI_H
#define ENVGUI_H

#include <QWidget>
#include <QProcess>

QT_BEGIN_NAMESPACE
namespace Ui { class EnvGui; }
QT_END_NAMESPACE


class EnvGui : public QWidget
{
    Q_OBJECT

public:
    explicit EnvGui(QWidget *parent = nullptr);
    ~EnvGui();

private:
    Ui::EnvGui *ui;
    QProcess *process;

    void selectExecutable();
    void addEnvironmentVariable();
    void launchApplication();
};

#endif // ENVGUI_H
