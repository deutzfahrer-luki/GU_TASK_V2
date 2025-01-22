QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    data/dataTask.cpp \
    main.cpp \
    view/AddTask/addtasks.cpp \
    view/AddUser/addusers.cpp \
    view/ChangeTask/changetask.cpp \
    view/mainwindow.cpp \
    util/date.cpp

HEADERS += \
    Controller/taskmanager.h \
    data/dataTask.h \
    data/jsonloader.h \
    model/RelativeDue.h \
    model/RelativeState.h \
    view/AddTask/addtasks.h \
    view/AddUser/addusers.h \
    view/ChangeTask/changetask.h \
    view/mainwindow.h \
    model/task.h \
    model/user.h \
    view/tasktablemodel.h \
    util/date.h

FORMS += \
    view/AddTask/addtasks.ui \
    view/AddUser/addusers.ui \
    view/ChangeTask/changetask.ui \
    view/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    data/tasks
