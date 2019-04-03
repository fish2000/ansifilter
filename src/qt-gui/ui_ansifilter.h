/********************************************************************************
** Form generated from reading UI file 'ansifilter.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANSIFILTER_H
#define UI_ANSIFILTER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_4;
    QPushButton *pbFileOpen;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pbSaveAs;
    QPushButton *pbClipboard;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lblDrop;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QComboBox *comboFormat;
    QGridLayout *gridLayout_2;
    QCheckBox *cbIgnoreSequences;
    QCheckBox *cbFragment;
    QCheckBox *cbOmitVersion;
    QCheckBox *cbIgnClearSeq;
    QCheckBox *cbDeriveStyles;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblSvgDim;
    QLineEdit *leSvgWidth;
    QLineEdit *leSvgHeight;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *gbAsciiArt;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *cbParseAsciiArt;
    QComboBox *comboAnsiFormat;
    QFrame *artSizeFrame;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lblWidth;
    QSpinBox *sbWidth;
    QSpacerItem *horizontalSpacer;
    QLabel *lblHeight;
    QSpinBox *sbHeight;
    QGridLayout *gridLayout_3;
    QLabel *lblTitle;
    QLineEdit *leTitle;
    QLabel *lblStyleFile;
    QLineEdit *leStyleFile;
    QLabel *lblEncoding;
    QComboBox *comboEncoding;
    QLabel *label_3;
    QSpinBox *spinBoxWrap;
    QFontComboBox *comboFont;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLineEdit *leColorMapPath;
    QPushButton *pbSelectMapFile;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pbAbout;
    QPushButton *pbExit;
    QVBoxLayout *verticalLayout;
    QLabel *lblInFilePath;
    QTextEdit *textEdit;
    QCheckBox *cbWatchFile;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->setWindowModality(Qt::NonModal);
        Dialog->resize(784, 791);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        Dialog->setAcceptDrops(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ansifilter.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        horizontalLayout_4 = new QHBoxLayout(Dialog);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        pbFileOpen = new QPushButton(groupBox);
        pbFileOpen->setObjectName(QString::fromUtf8("pbFileOpen"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pbFileOpen->sizePolicy().hasHeightForWidth());
        pbFileOpen->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(pbFileOpen, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_5, 0, 1, 1, 1);

        pbSaveAs = new QPushButton(groupBox);
        pbSaveAs->setObjectName(QString::fromUtf8("pbSaveAs"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pbSaveAs->sizePolicy().hasHeightForWidth());
        pbSaveAs->setSizePolicy(sizePolicy3);

        gridLayout_4->addWidget(pbSaveAs, 1, 0, 1, 1);

        pbClipboard = new QPushButton(groupBox);
        pbClipboard->setObjectName(QString::fromUtf8("pbClipboard"));
        sizePolicy3.setHeightForWidth(pbClipboard->sizePolicy().hasHeightForWidth());
        pbClipboard->setSizePolicy(sizePolicy3);

        gridLayout_4->addWidget(pbClipboard, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_4);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_4 = new QSpacerItem(13, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 2, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(13, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        lblDrop = new QLabel(groupBox);
        lblDrop->setObjectName(QString::fromUtf8("lblDrop"));
        lblDrop->setEnabled(false);
        lblDrop->setMaximumSize(QSize(48, 48));
        lblDrop->setPixmap(QPixmap(QString::fromUtf8(":/Actions-drop-icon.png")));
        lblDrop->setScaledContents(true);

        gridLayout->addWidget(lblDrop, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_6->addWidget(label_4);

        comboFormat = new QComboBox(groupBox);
        comboFormat->addItem(QString());
        comboFormat->addItem(QString());
        comboFormat->addItem(QString());
        comboFormat->addItem(QString());
        comboFormat->addItem(QString());
        comboFormat->addItem(QString());
        comboFormat->addItem(QString());
        comboFormat->addItem(QString());
        comboFormat->setObjectName(QString::fromUtf8("comboFormat"));
        comboFormat->setEnabled(true);

        horizontalLayout_6->addWidget(comboFormat);


        verticalLayout_2->addLayout(horizontalLayout_6);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        cbIgnoreSequences = new QCheckBox(groupBox);
        cbIgnoreSequences->setObjectName(QString::fromUtf8("cbIgnoreSequences"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(cbIgnoreSequences->sizePolicy().hasHeightForWidth());
        cbIgnoreSequences->setSizePolicy(sizePolicy4);

        gridLayout_2->addWidget(cbIgnoreSequences, 0, 0, 1, 1);

        cbFragment = new QCheckBox(groupBox);
        cbFragment->setObjectName(QString::fromUtf8("cbFragment"));
        sizePolicy4.setHeightForWidth(cbFragment->sizePolicy().hasHeightForWidth());
        cbFragment->setSizePolicy(sizePolicy4);

        gridLayout_2->addWidget(cbFragment, 0, 1, 1, 1);

        cbOmitVersion = new QCheckBox(groupBox);
        cbOmitVersion->setObjectName(QString::fromUtf8("cbOmitVersion"));

        gridLayout_2->addWidget(cbOmitVersion, 1, 0, 1, 1);

        cbIgnClearSeq = new QCheckBox(groupBox);
        cbIgnClearSeq->setObjectName(QString::fromUtf8("cbIgnClearSeq"));

        gridLayout_2->addWidget(cbIgnClearSeq, 1, 1, 1, 1);

        cbDeriveStyles = new QCheckBox(groupBox);
        cbDeriveStyles->setObjectName(QString::fromUtf8("cbDeriveStyles"));

        gridLayout_2->addWidget(cbDeriveStyles, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lblSvgDim = new QLabel(groupBox);
        lblSvgDim->setObjectName(QString::fromUtf8("lblSvgDim"));

        horizontalLayout_2->addWidget(lblSvgDim);

        leSvgWidth = new QLineEdit(groupBox);
        leSvgWidth->setObjectName(QString::fromUtf8("leSvgWidth"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(leSvgWidth->sizePolicy().hasHeightForWidth());
        leSvgWidth->setSizePolicy(sizePolicy5);
        leSvgWidth->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(leSvgWidth);

        leSvgHeight = new QLineEdit(groupBox);
        leSvgHeight->setObjectName(QString::fromUtf8("leSvgHeight"));
        sizePolicy5.setHeightForWidth(leSvgHeight->sizePolicy().hasHeightForWidth());
        leSvgHeight->setSizePolicy(sizePolicy5);
        leSvgHeight->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(leSvgHeight);


        gridLayout_2->addLayout(horizontalLayout_2, 2, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer_4);

        gbAsciiArt = new QGroupBox(groupBox);
        gbAsciiArt->setObjectName(QString::fromUtf8("gbAsciiArt"));
        gbAsciiArt->setEnabled(true);
        sizePolicy3.setHeightForWidth(gbAsciiArt->sizePolicy().hasHeightForWidth());
        gbAsciiArt->setSizePolicy(sizePolicy3);
        gbAsciiArt->setFlat(false);
        gridLayout_5 = new QGridLayout(gbAsciiArt);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        cbParseAsciiArt = new QCheckBox(gbAsciiArt);
        cbParseAsciiArt->setObjectName(QString::fromUtf8("cbParseAsciiArt"));

        horizontalLayout_3->addWidget(cbParseAsciiArt);

        comboAnsiFormat = new QComboBox(gbAsciiArt);
        comboAnsiFormat->addItem(QString());
        comboAnsiFormat->addItem(QString());
        comboAnsiFormat->addItem(QString());
        comboAnsiFormat->setObjectName(QString::fromUtf8("comboAnsiFormat"));
        comboAnsiFormat->setEnabled(false);
        comboAnsiFormat->setEditable(false);
        comboAnsiFormat->setMaxVisibleItems(3);
        comboAnsiFormat->setMaxCount(3);

        horizontalLayout_3->addWidget(comboAnsiFormat);


        gridLayout_5->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        artSizeFrame = new QFrame(gbAsciiArt);
        artSizeFrame->setObjectName(QString::fromUtf8("artSizeFrame"));
        artSizeFrame->setEnabled(false);
        artSizeFrame->setFrameShape(QFrame::StyledPanel);
        artSizeFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(artSizeFrame);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        lblWidth = new QLabel(artSizeFrame);
        lblWidth->setObjectName(QString::fromUtf8("lblWidth"));
        lblWidth->setEnabled(false);

        horizontalLayout_7->addWidget(lblWidth);

        sbWidth = new QSpinBox(artSizeFrame);
        sbWidth->setObjectName(QString::fromUtf8("sbWidth"));
        sbWidth->setEnabled(false);
        sbWidth->setMinimum(60);
        sbWidth->setMaximum(320);
        sbWidth->setSingleStep(5);
        sbWidth->setValue(80);

        horizontalLayout_7->addWidget(sbWidth);

        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        lblHeight = new QLabel(artSizeFrame);
        lblHeight->setObjectName(QString::fromUtf8("lblHeight"));
        lblHeight->setEnabled(false);

        horizontalLayout_7->addWidget(lblHeight);

        sbHeight = new QSpinBox(artSizeFrame);
        sbHeight->setObjectName(QString::fromUtf8("sbHeight"));
        sbHeight->setEnabled(false);
        sbHeight->setMinimum(80);
        sbHeight->setMaximum(500);
        sbHeight->setSingleStep(5);
        sbHeight->setValue(150);

        horizontalLayout_7->addWidget(sbHeight);


        gridLayout_5->addWidget(artSizeFrame, 1, 0, 1, 1);


        verticalLayout_2->addWidget(gbAsciiArt);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        lblTitle = new QLabel(groupBox);
        lblTitle->setObjectName(QString::fromUtf8("lblTitle"));
        QSizePolicy sizePolicy6(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(lblTitle->sizePolicy().hasHeightForWidth());
        lblTitle->setSizePolicy(sizePolicy6);

        gridLayout_3->addWidget(lblTitle, 0, 0, 1, 1);

        leTitle = new QLineEdit(groupBox);
        leTitle->setObjectName(QString::fromUtf8("leTitle"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(leTitle->sizePolicy().hasHeightForWidth());
        leTitle->setSizePolicy(sizePolicy7);

        gridLayout_3->addWidget(leTitle, 0, 1, 1, 2);

        lblStyleFile = new QLabel(groupBox);
        lblStyleFile->setObjectName(QString::fromUtf8("lblStyleFile"));

        gridLayout_3->addWidget(lblStyleFile, 1, 0, 1, 1);

        leStyleFile = new QLineEdit(groupBox);
        leStyleFile->setObjectName(QString::fromUtf8("leStyleFile"));

        gridLayout_3->addWidget(leStyleFile, 1, 1, 1, 2);

        lblEncoding = new QLabel(groupBox);
        lblEncoding->setObjectName(QString::fromUtf8("lblEncoding"));
        sizePolicy1.setHeightForWidth(lblEncoding->sizePolicy().hasHeightForWidth());
        lblEncoding->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(lblEncoding, 2, 0, 1, 1);

        comboEncoding = new QComboBox(groupBox);
        comboEncoding->addItem(QString());
        comboEncoding->addItem(QString());
        comboEncoding->addItem(QString());
        comboEncoding->addItem(QString());
        comboEncoding->addItem(QString());
        comboEncoding->addItem(QString());
        comboEncoding->addItem(QString());
        comboEncoding->addItem(QString());
        comboEncoding->addItem(QString());
        comboEncoding->addItem(QString());
        comboEncoding->addItem(QString());
        comboEncoding->addItem(QString());
        comboEncoding->addItem(QString());
        comboEncoding->addItem(QString());
        comboEncoding->setObjectName(QString::fromUtf8("comboEncoding"));
        sizePolicy7.setHeightForWidth(comboEncoding->sizePolicy().hasHeightForWidth());
        comboEncoding->setSizePolicy(sizePolicy7);
        comboEncoding->setEditable(true);

        gridLayout_3->addWidget(comboEncoding, 2, 2, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 3, 0, 1, 1);

        spinBoxWrap = new QSpinBox(groupBox);
        spinBoxWrap->setObjectName(QString::fromUtf8("spinBoxWrap"));

        gridLayout_3->addWidget(spinBoxWrap, 3, 2, 1, 1);

        comboFont = new QFontComboBox(groupBox);
        comboFont->setObjectName(QString::fromUtf8("comboFont"));
        QFont font;
        font.setFamily(QString::fromUtf8("Liberation Mono"));
        comboFont->setCurrentFont(font);

        gridLayout_3->addWidget(comboFont, 4, 0, 1, 2);


        verticalLayout_2->addLayout(gridLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        leColorMapPath = new QLineEdit(groupBox);
        leColorMapPath->setObjectName(QString::fromUtf8("leColorMapPath"));
        QSizePolicy sizePolicy8(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(leColorMapPath->sizePolicy().hasHeightForWidth());
        leColorMapPath->setSizePolicy(sizePolicy8);

        horizontalLayout->addWidget(leColorMapPath);

        pbSelectMapFile = new QPushButton(groupBox);
        pbSelectMapFile->setObjectName(QString::fromUtf8("pbSelectMapFile"));
        QSizePolicy sizePolicy9(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(pbSelectMapFile->sizePolicy().hasHeightForWidth());
        pbSelectMapFile->setSizePolicy(sizePolicy9);
        pbSelectMapFile->setMinimumSize(QSize(20, 0));

        horizontalLayout->addWidget(pbSelectMapFile);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pbAbout = new QPushButton(groupBox);
        pbAbout->setObjectName(QString::fromUtf8("pbAbout"));
        sizePolicy3.setHeightForWidth(pbAbout->sizePolicy().hasHeightForWidth());
        pbAbout->setSizePolicy(sizePolicy3);

        horizontalLayout_5->addWidget(pbAbout);

        pbExit = new QPushButton(groupBox);
        pbExit->setObjectName(QString::fromUtf8("pbExit"));
        sizePolicy3.setHeightForWidth(pbExit->sizePolicy().hasHeightForWidth());
        pbExit->setSizePolicy(sizePolicy3);
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        pbExit->setFont(font1);

        horizontalLayout_5->addWidget(pbExit);


        verticalLayout_2->addLayout(horizontalLayout_5);


        horizontalLayout_4->addWidget(groupBox);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lblInFilePath = new QLabel(Dialog);
        lblInFilePath->setObjectName(QString::fromUtf8("lblInFilePath"));

        verticalLayout->addWidget(lblInFilePath);

        textEdit = new QTextEdit(Dialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QSizePolicy sizePolicy10(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy10.setHorizontalStretch(1);
        sizePolicy10.setVerticalStretch(1);
        sizePolicy10.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy10);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Monospace"));
        font2.setPointSize(10);
        textEdit->setFont(font2);
        textEdit->setAcceptDrops(false);
        textEdit->setReadOnly(true);

        verticalLayout->addWidget(textEdit);

        cbWatchFile = new QCheckBox(Dialog);
        cbWatchFile->setObjectName(QString::fromUtf8("cbWatchFile"));
        cbWatchFile->setEnabled(false);

        verticalLayout->addWidget(cbWatchFile);


        horizontalLayout_4->addLayout(verticalLayout);

#ifndef QT_NO_SHORTCUT
        lblTitle->setBuddy(leTitle);
        lblEncoding->setBuddy(comboEncoding);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(cbIgnoreSequences, cbFragment);
        QWidget::setTabOrder(cbFragment, leTitle);
        QWidget::setTabOrder(leTitle, comboEncoding);
        QWidget::setTabOrder(comboEncoding, comboFont);
        QWidget::setTabOrder(comboFont, textEdit);

        retranslateUi(Dialog);
        QObject::connect(pbExit, SIGNAL(clicked()), Dialog, SLOT(close()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "ANSIFilter", nullptr));
        groupBox->setTitle(QApplication::translate("Dialog", "ANSIFilter", nullptr));
#ifndef QT_NO_TOOLTIP
        pbFileOpen->setToolTip(QApplication::translate("Dialog", "Open a text file.", nullptr));
#endif // QT_NO_TOOLTIP
        pbFileOpen->setText(QApplication::translate("Dialog", "Open File", nullptr));
#ifndef QT_NO_TOOLTIP
        pbSaveAs->setToolTip(QApplication::translate("Dialog", "Save the opened file as text, HTML, LaTeX, Plain TeX, BBCode or RTF.", nullptr));
#endif // QT_NO_TOOLTIP
        pbSaveAs->setText(QApplication::translate("Dialog", "Save as", nullptr));
#ifndef QT_NO_TOOLTIP
        pbClipboard->setToolTip(QApplication::translate("Dialog", "Copy opened file as plain text to clipboard", nullptr));
#endif // QT_NO_TOOLTIP
        pbClipboard->setText(QApplication::translate("Dialog", "Copy to clipboard", nullptr));
#ifndef QT_NO_TOOLTIP
        lblDrop->setToolTip(QApplication::translate("Dialog", "You may drop a file on this window.", nullptr));
#endif // QT_NO_TOOLTIP
        lblDrop->setText(QString());
        label_4->setText(QApplication::translate("Dialog", "Output format:", nullptr));
        comboFormat->setItemText(0, QApplication::translate("Dialog", "Text", nullptr));
        comboFormat->setItemText(1, QApplication::translate("Dialog", "HTML", nullptr));
        comboFormat->setItemText(2, QApplication::translate("Dialog", "RTF", nullptr));
        comboFormat->setItemText(3, QApplication::translate("Dialog", "LaTeX", nullptr));
        comboFormat->setItemText(4, QApplication::translate("Dialog", "TeX", nullptr));
        comboFormat->setItemText(5, QApplication::translate("Dialog", "BBCode", nullptr));
        comboFormat->setItemText(6, QApplication::translate("Dialog", "Pango Markup", nullptr));
        comboFormat->setItemText(7, QApplication::translate("Dialog", "SVG", nullptr));

#ifndef QT_NO_TOOLTIP
        cbIgnoreSequences->setToolTip(QApplication::translate("Dialog", "Show and save files ignoring the contained ANSI formatting information.", nullptr));
#endif // QT_NO_TOOLTIP
        cbIgnoreSequences->setText(QApplication::translate("Dialog", "Omit styling in output", nullptr));
#ifndef QT_NO_TOOLTIP
        cbFragment->setToolTip(QApplication::translate("Dialog", "Save HTML without header and footer to paste it into existing documents.", nullptr));
#endif // QT_NO_TOOLTIP
        cbFragment->setText(QApplication::translate("Dialog", "Omit header and footer", nullptr));
#ifndef QT_NO_TOOLTIP
        cbOmitVersion->setToolTip(QApplication::translate("Dialog", "Do not include version info comment", nullptr));
#endif // QT_NO_TOOLTIP
        cbOmitVersion->setText(QApplication::translate("Dialog", "Omit version info", nullptr));
#ifndef QT_NO_TOOLTIP
        cbIgnClearSeq->setToolTip(QApplication::translate("Dialog", "Do not adhere to clear (ESC K) commands", nullptr));
#endif // QT_NO_TOOLTIP
        cbIgnClearSeq->setText(QApplication::translate("Dialog", "Ignore Clear Sequences", nullptr));
#ifndef QT_NO_TOOLTIP
        cbDeriveStyles->setToolTip(QApplication::translate("Dialog", "Generate Stylesheets based on the formatting information", nullptr));
#endif // QT_NO_TOOLTIP
        cbDeriveStyles->setText(QApplication::translate("Dialog", "Derive Stylesheets", nullptr));
        lblSvgDim->setText(QApplication::translate("Dialog", "SVG dim.:", nullptr));
#ifndef QT_NO_TOOLTIP
        leSvgWidth->setToolTip(QApplication::translate("Dialog", "Document width (units allowed)", nullptr));
#endif // QT_NO_TOOLTIP
        leSvgWidth->setPlaceholderText(QApplication::translate("Dialog", "300px", nullptr));
#ifndef QT_NO_TOOLTIP
        leSvgHeight->setToolTip(QApplication::translate("Dialog", "Document height (units allowed)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        leSvgHeight->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        leSvgHeight->setPlaceholderText(QApplication::translate("Dialog", "450px", nullptr));
        gbAsciiArt->setTitle(QApplication::translate("Dialog", "ANSI art options", nullptr));
#ifndef QT_NO_TOOLTIP
        cbParseAsciiArt->setToolTip(QApplication::translate("Dialog", "Enable parsing of ANSI art files.", nullptr));
#endif // QT_NO_TOOLTIP
        cbParseAsciiArt->setText(QApplication::translate("Dialog", "Enable ANSI art", nullptr));
        comboAnsiFormat->setItemText(0, QApplication::translate("Dialog", "Codepage 437", nullptr));
        comboAnsiFormat->setItemText(1, QApplication::translate("Dialog", "BIN/XBIN", nullptr));
        comboAnsiFormat->setItemText(2, QApplication::translate("Dialog", "Tundra", nullptr));

#ifndef QT_NO_TOOLTIP
        comboAnsiFormat->setToolTip(QApplication::translate("Dialog", "Select the ANSI art file format", nullptr));
#endif // QT_NO_TOOLTIP
        lblWidth->setText(QApplication::translate("Dialog", "Width", nullptr));
#ifndef QT_NO_TOOLTIP
        sbWidth->setToolTip(QApplication::translate("Dialog", "Set the ASCII art image width (default: 80). This setting is ignored with XBIN input.", nullptr));
#endif // QT_NO_TOOLTIP
        lblHeight->setText(QApplication::translate("Dialog", "Height", nullptr));
#ifndef QT_NO_TOOLTIP
        sbHeight->setToolTip(QApplication::translate("Dialog", "Set the ASCII art image height (default: 150). This setting is ignored with XBIN input.", nullptr));
#endif // QT_NO_TOOLTIP
        lblTitle->setText(QApplication::translate("Dialog", "Tit&le:", nullptr));
#ifndef QT_NO_TOOLTIP
        leTitle->setToolTip(QApplication::translate("Dialog", "Set the output document title.", nullptr));
#endif // QT_NO_TOOLTIP
        leTitle->setPlaceholderText(QApplication::translate("Dialog", "My Title", nullptr));
        lblStyleFile->setText(QApplication::translate("Dialog", "Style file:", nullptr));
#ifndef QT_NO_TOOLTIP
        leStyleFile->setToolTip(QApplication::translate("Dialog", "Enter the name of a referenced stylesheet file here.", nullptr));
#endif // QT_NO_TOOLTIP
        leStyleFile->setPlaceholderText(QApplication::translate("Dialog", "my-style.css", nullptr));
        lblEncoding->setText(QApplication::translate("Dialog", "E&ncoding:", nullptr));
        comboEncoding->setItemText(0, QApplication::translate("Dialog", "ISO-8859-1", nullptr));
        comboEncoding->setItemText(1, QApplication::translate("Dialog", "ISO-8859-2", nullptr));
        comboEncoding->setItemText(2, QApplication::translate("Dialog", "ISO-8859-3", nullptr));
        comboEncoding->setItemText(3, QApplication::translate("Dialog", "ISO-8859-4", nullptr));
        comboEncoding->setItemText(4, QApplication::translate("Dialog", "ISO-8859-6", nullptr));
        comboEncoding->setItemText(5, QApplication::translate("Dialog", "ISO-8859-7", nullptr));
        comboEncoding->setItemText(6, QApplication::translate("Dialog", "ISO-8859-8", nullptr));
        comboEncoding->setItemText(7, QApplication::translate("Dialog", "ISO-8859-9", nullptr));
        comboEncoding->setItemText(8, QApplication::translate("Dialog", "ISO-8859-10", nullptr));
        comboEncoding->setItemText(9, QApplication::translate("Dialog", "ISO-8859-11", nullptr));
        comboEncoding->setItemText(10, QApplication::translate("Dialog", "ISO-8859-13", nullptr));
        comboEncoding->setItemText(11, QApplication::translate("Dialog", "ISO-8859-14", nullptr));
        comboEncoding->setItemText(12, QApplication::translate("Dialog", "ISO-8859-15", nullptr));
        comboEncoding->setItemText(13, QApplication::translate("Dialog", "UTF-8", nullptr));

#ifndef QT_NO_TOOLTIP
        comboEncoding->setToolTip(QApplication::translate("Dialog", "Set the encoding (has to match input file encoding).", nullptr));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("Dialog", "Line wrap:", nullptr));
#ifndef QT_NO_TOOLTIP
        spinBoxWrap->setToolTip(QApplication::translate("Dialog", "Wrap lines after given char count (0 disables wrapping).", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        comboFont->setToolTip(QApplication::translate("Dialog", "Set the output font.", nullptr));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("Dialog", "Color map file:", nullptr));
#ifndef QT_NO_TOOLTIP
        leColorMapPath->setToolTip(QApplication::translate("Dialog", "Color map file (see README for details). This setting is ignored with XBIN input.", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pbSelectMapFile->setToolTip(QApplication::translate("Dialog", "Select a color map configuration file. ", nullptr));
#endif // QT_NO_TOOLTIP
        pbSelectMapFile->setText(QApplication::translate("Dialog", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        pbAbout->setToolTip(QApplication::translate("Dialog", "Show information about this program.", nullptr));
#endif // QT_NO_TOOLTIP
        pbAbout->setText(QApplication::translate("Dialog", "About", nullptr));
#ifndef QT_NO_TOOLTIP
        pbExit->setToolTip(QApplication::translate("Dialog", "Quit this program.", nullptr));
#endif // QT_NO_TOOLTIP
        pbExit->setText(QApplication::translate("Dialog", "Quit", nullptr));
        lblInFilePath->setText(QApplication::translate("Dialog", "Input file:", nullptr));
#ifndef QT_NO_TOOLTIP
        textEdit->setToolTip(QApplication::translate("Dialog", "Output preview", nullptr));
#endif // QT_NO_TOOLTIP
        textEdit->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Monospace'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Noto Sans,Courier New';\">Please open a file.</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        cbWatchFile->setToolTip(QApplication::translate("Dialog", "Update view if input file changes, Do not apply with big or fast growing input files.", nullptr));
#endif // QT_NO_TOOLTIP
        cbWatchFile->setText(QApplication::translate("Dialog", "Watch this file", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANSIFILTER_H
