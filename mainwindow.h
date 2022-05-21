#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_editingFinished();

    void on_lineEdit_2_editingFinished();

    void on_lineEdit_3_editingFinished();

    void checkFill();

    void tab2_checkFill();

    void on_pushButton_2_clicked();

    void tab1_init();

    void tab2_init();

    void tab3_init();

    void on_tab2_btnCalc_clicked();

    void on_tW_task1_currentChanged(int index);

    void on_tab2_btnClear_clicked();

    void on_tab2_inputA_editingFinished();

    void on_tab2_inputB_editingFinished();

    void on_tab2_inputAngle_editingFinished();


    void on_tab3_pB_Move_clicked();

    void on_tab3_pB_Swap_clicked();

    void on_tab3_pB_HTML_clicked();

    void on_tab3_pB_Clear_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
