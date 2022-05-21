#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
* Домашнее задание к уроку 1
* курса "Разработка программ с графическим интерфейсом на С++"
* автор Недокунев А.В.
* среда разработки:
* MinGW64
* Qt 6.2.3
* Qt Creator 7.0.0
* CMake
* codepage UTF-8
*/

void MainWindow::tab1_init() // инициализация очистка первой вкладки для задания 1
{
    ui->lineEdit->setText(QString::number(0));
    ui->lineEdit_2->setText(QString::number(0));
    ui->lineEdit_3->setText(QString::number(0));
    ui->pushButton->setEnabled(false);
    ui->label_5->setText("Fill coefficients");
}

void MainWindow::tab2_init() // инициализация очистка второй вкладки для задания 2
{
    ui->tab2_inputA->setText(QString::number(0));
    ui->tab2_inputB->setText(QString::number(0));
    ui->tab2_inputAngle->setText(QString::number(0));
    ui->tab2_btnCalc->setEnabled(false);
    ui->tab2_result->setText("Fill data");
    ui->radioButton->setChecked(true);
}

void MainWindow::tab3_init() // инициализация очистка третьей вкладки для задания 3
{
    ui->tab3_plainTextEdit_1->setPlainText("Text for test for plainTextEdit_1");
    ui->tab3_plainTextEdit_2->setPlainText("Text for test for plainTextEdit_2");
}

void MainWindow::on_tW_task1_currentChanged(int index) // выбор вкладки
{
    if (index == 0)
    {
        tab1_init();
    }
    else if (index == 1)
    {
        tab2_init();
    }
    else
    {
        tab3_init();
    }
}

/* Задание 1
 * Написать программу, которая будет находить корень квадратного уравнения второй степени,
 * входные данные: a, b, c. Если нахождение корня невозможно,
 * выводить сообщение в поле результата (или выводить результат в виде комплексного числа).
 * Учитывать, что число a может быть равно нулю.
*/

void MainWindow::on_pushButton_clicked() // находим корни/корень уравнения
{
    int cA, cB, cC; // коэффиценты уравнения
    double X1 = 0.0, X2 = 0.0, D = 0.0; // корни и дискриминант
    QString result = ""; // строка результата для вывода в поле

    // получаем коэффициенты из полей ввода
    cA = ui->lineEdit->text().toInt();
    cB = ui->lineEdit_2->text().toInt();
    cC = ui->lineEdit_3->text().toInt();

    if (cA == 0) // случай, если первый коэффициент равен 0
    {
       X1 = -cC / cB; // находим корень
       result = "X = " + QString::number(X1); // формируем результат
    }
    else
    {
        D = pow(cB,2) - 4*cA*cC; // дискриминант
        if (D > 0) // больше 0 - два корня
        {
            X1 = (-cB + sqrt(D))/(2*cA);
            X2 = (-cB - sqrt(D))/(2*cA);
            result = "X1 = " + QString::number(X1) + "; X2 = " + QString::number(X2);
        }
        else if (D == 0) // равен 0 - один корень
        {
            X1 = -cB / (2*cA);
            result = "X = " + QString::number(X1);
        }
        else // меньше 0 - нет корней
        {
            result = "NO RESULT";
        }
    }
    ui->label_5->setText(result); // выводим результат
}

void MainWindow::checkFill() // проверка полей ввода для активации кнопки <Calc>
{
    if ((ui->lineEdit_2->text().toInt() != 0) & (ui->lineEdit_3->text().toInt() != 0))
    {
        ui->pushButton->setEnabled(true);
    }
    else
    {
        ui->pushButton->setEnabled(false);
    }
}

// проверяем поля ввода для активации кнопки "Calc"
void MainWindow::on_lineEdit_editingFinished()
{
    checkFill();
}

void MainWindow::on_lineEdit_2_editingFinished()
{
    checkFill();
}

void MainWindow::on_lineEdit_3_editingFinished()
{
    checkFill();
}


void MainWindow::on_pushButton_2_clicked() // очищаем форму
{
    tab1_init();
}

/* Задание 2
 * Расчет стороны треугольника по двум сторонам и углом между ними.
 * Дополнительно: добавить переключатель из QRadioButton для выбора единиц,
 * в каких указан угол: градусах или радианах.
 */

void MainWindow::on_tab2_btnCalc_clicked() // собственно сам расчет при нажатии на кнопку <Calc>
{
    double tA = 0.0, tB = 0.0; // стороны треугольника
    float tAngle = 0.0; // угол между сторонами
    double tC = 0.0; // искомая третья сторона
    tA = ui->tab2_inputA->text().toDouble(); // получаем значение первой стороны из поля для ввода
    tB = ui->tab2_inputB->text().toDouble(); // получаем значение второй стороны из поля для ввода

    if (ui->radioButton->isChecked()){ // собственно тот самый переключчатель выбора единиц
        tAngle = qDegreesToRadians(ui->tab2_inputAngle->text().toFloat()); // поскольку функция qCos() принимает радианы, а выбраны градусы - конвертируем...
    }
    else
    {
        tAngle = ui->tab2_inputAngle->text().toFloat(); // выбраны радианы - их и получаем...
    }

    tC = sqrt(pow(tA,2) + pow(tB,2) - 2*tA*tB*qCos(tAngle)); // находим значение третьей стороны по двум известным и углу между ними...
    ui->tab2_result->setText(QString::number(tC)); // выводим найденное значение
}


void MainWindow::on_tab2_btnClear_clicked() // очищаем форму
{
    tab2_init();
}

// проверяем поля ввода для активации кнопки "Calc"
void MainWindow::on_tab2_inputA_editingFinished()
{
    tab2_checkFill();
}


void MainWindow::on_tab2_inputB_editingFinished()
{
    tab2_checkFill();
}


void MainWindow::on_tab2_inputAngle_editingFinished()
{
    tab2_checkFill();
}


void MainWindow::tab2_checkFill() // проверка полей ввода для активации кнопки <Calc>
{
    if ((ui->tab2_inputA->text().toInt() != 0) & (ui->tab2_inputB->text().toInt() != 0) & (ui->tab2_inputAngle->text().toFloat() != 0.0))
    {
        ui->tab2_btnCalc->setEnabled(true);
    }
    else
    {
        ui->tab2_btnCalc->setEnabled(false);
    }
}

/* Задание 3
 * Создать программу, разместить два виджета QPlainTextEdit.
 * Добавить две кнопки:
 * первая кнопка будет добавлять текст из одного текстового виджета в другой,
 * вторая кнопка - заменять текст в одном виджете на текст в другом виджете.
 * Добавить третью кнопку, которая вставляет в один из текстовый виджет текст произвольного html-кода,
 * например <font color='red'>Hello</font> (используйте метод setHtml(QString) ).
 */

void MainWindow::on_tab3_pB_Move_clicked() // первая кнопка
{
    ui->tab3_plainTextEdit_2->setPlainText(ui->tab3_plainTextEdit_1->toPlainText());
}


void MainWindow::on_tab3_pB_Swap_clicked() // вторая кнопка
{
    QString strTemp;
    strTemp = ui->tab3_plainTextEdit_1->toPlainText();
    ui->tab3_plainTextEdit_1->setPlainText(ui->tab3_plainTextEdit_2->toPlainText());
    ui->tab3_plainTextEdit_2->setPlainText(strTemp);
}


void MainWindow::on_tab3_pB_HTML_clicked() // третья кнопка
{
    ui->tab3_plainTextEdit_1->appendHtml("<font color='red'>Text from html code</font>");
}


void MainWindow::on_tab3_pB_Clear_clicked() // кнопка очистки_инициализации
{
    tab3_init();
}

