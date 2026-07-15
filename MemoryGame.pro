QT += core gui widgets multimedia network sql

CONFIG += qt warn_on release
CONFIG += c++17

TARGET = MemoryGame
TEMPLATE = app

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += \
    aboutdialog.cpp \
    carta.cpp \
    cartaarmadilha.cpp \
    cartabonus.cpp \
    cartacomum.cpp \
    funcoes.cpp \
    jogo.cpp \
    main.cpp \
    mainwindow.cpp \
    placar.cpp \
    pontuacao.cpp \
    settings.cpp \
    victory.cpp

HEADERS += \
    aboutdialog.h \
    carta.h \
    cartaarmadilha.h \
    cartabonus.h \
    cartacomum.h \
    conexao.h \
    funcoes.h \
    jogo.h \
    mainwindow.h \
    placar.h \
    pontuacao.h \
    settings.h \
    victory.h

FORMS += \
    aboutdialog.ui \
    mainwindow.ui \
    placar.ui \
    settings.ui \
    victory.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Cards.qrc \
    Foto.qrc \
    Songs.qrc \
    Sounds.qrc
