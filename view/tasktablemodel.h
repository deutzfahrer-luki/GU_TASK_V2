// TaskTableModel.h
#ifndef TASKTABLEMODEL_H
#define TASKTABLEMODEL_H
#define COLUMN_COUNT 6

#include <QTableView>
#include <QAbstractTableModel>
#include "model/task.h"
#include "model/RelativeDue.h"


// Die TaskTableModel-Klasse stellt die Aufgaben-Daten als Tabelle dar.
// Sie erbt von QAbstractTableModel, was bedeutet, dass wir die Datenstruktur und
// das Verhalten der Tabelle selbst definieren können.
class TaskTableModel : public QAbstractTableModel {
    Q_OBJECT  // Qt-Makro für Klassen, die Qt-spezifische Funktionen wie Signale/Slots verwenden.
public:
    // Konstruktor: Initialisiert das Modell, optional mit einem Eltern-Widget.
    explicit TaskTableModel(QObject *parent = nullptr)
        : QAbstractTableModel(parent) {}

    // Funktion zum Setzen der Aufgaben-Liste (Erneuert die Anzeige, wenn neue Daten vorhanden sind).
    void setTasks(const QVector<Task> &tasks) {
        beginResetModel();  // Informiert die Tabelle, dass eine Änderung bevorsteht
        m_tasks = tasks;  // Speichert die neuen Aufgaben
        endResetModel();  // Signalisiert der Tabelle, dass die Daten aktualisiert wurden
    }

    // Gibt die Anzahl der Zeilen zurück, also die Anzahl der Aufgaben.
    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        Q_UNUSED(parent);  // Wir verwenden hier kein Parent-Modell, daher wird es ignoriert.
        return m_tasks.size();  // Die Anzahl der Aufgaben (Anzahl der Zeilen in der Tabelle)
    }

    // Gibt die Anzahl der Spalten zurück. Wir haben vier Spalten (ID, Beschreibung, Fälligkeitsdatum, Zugewiesene).
    int columnCount(const QModelIndex &parent = QModelIndex()) const override {
        Q_UNUSED(parent);  // Parent wird wieder ignoriert.
        return COLUMN_COUNT;
    }

    // Gibt die Daten für eine bestimmte Zelle zurück, basierend auf Zeile und Spalte.
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override {
        // Überprüft, ob der Index gültig ist und ob die Rolle eine Anzeige-Rolle ist.
        if (!index.isValid()) {
            return QVariant();  // Keine Daten zurückgeben, wenn der Index ungültig ist
        }

        // Holt die Aufgabe für die aktuelle Zeile
        const Task &task = m_tasks[index.row()];

        switch (role) {
        case Qt::DisplayRole:
            // Gibt die Daten basierend auf der Spalte zurück
            switch (index.column()) {
            case 0:
                return QString::fromStdString(std::to_string(task.getId()));   // Spalte 0: Die ID der Aufgabe
            case 1:
                return QString::fromStdString(task.getDescription());  // Spalte 1: Die Beschreibung der Aufgabe
            case 2:
                return QString::fromStdString(task.getDue());  // Spalte 2: Das Fälligkeitsdatum der Aufgabe
            case 3:
                return QString::fromStdString(task.getAssignee());  // Spalte 3: Die zugewiesenen Personen als kommagetrennte Liste
            case 4:
                return QString::fromStdString(task.getStateByString());
            case 5:
                return QString::fromStdString(relativeDueToday(task.getDue()));  // Spalte 5: Relative Due
            default:
                return QVariant();  // Für ungültige Spalten keine Daten zurückgeben
            }

        case Qt::BackgroundRole:  // Hintergrundfarbe
            // Wenn wir in der letzten Spalte sind (Relative Due)
            if (index.column() == 5) {
                QString relativeDue = QString::fromStdString(relativeDueToday(task.getDue()));

                // Setze die Hintergrundfarbe basierend auf dem Wert in der letzten Spalte
                if (relativeDue == "Overdue") {
                    return QBrush(Qt::red);  // Überfällig -> Rot
                } else if (relativeDue == "Today") {
                    return QBrush(Qt::green);  // Heute -> Grün
                } else if (relativeDue == "Tomorrow") {
                    return QBrush(Qt::yellow);  // Morgen -> Gelb
                } else if (relativeDue == "ThisWeek") {
                    return QBrush(Qt::cyan);  // Diese Woche -> Cyan
                } else if (relativeDue == "ThisMonth") {
                    return QBrush(Qt::blue);  // Diesen Monat -> Blau
                } else {
                    return QBrush(Qt::lightGray);  // Sonst -> Hellgrau
                }
            }
            break;

        case Qt::ForegroundRole:  // Textfarbe
            // Wenn wir in der letzten Spalte sind (Relative Due)
            if (index.column() == 5) {
                QString relativeDue = QString::fromStdString(relativeDueToday(task.getDue()));

                // Setze die Textfarbe basierend auf dem Wert in der letzten Spalte
                if (relativeDue == "Overdue") {
                    return QBrush(Qt::white);  // Überfällig -> Weiße Schrift
                } else if (relativeDue == "Today") {
                    return QBrush(Qt::black);  // Heute -> Schwarze Schrift
                } else if (relativeDue == "Tomorrow") {
                    return QBrush(Qt::black);  // Morgen -> Schwarze Schrift
                } else {
                    return QBrush(Qt::black);  // Sonst -> Schwarze Schrift
                }
            }
            break;

        default:
            return QVariant();  // Für andere Rollen keine Daten zurückgeben
        }

        return QVariant();  // Standard Rückgabewert
    }


    // Gibt die Überschriften für die Spalten zurück, z. B. "ID", "Beschreibung", etc.
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override {
        if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
            // Gibt die Überschriften für jede Spalte zurück.
            switch (section) {
            case 0:
                return QString("ID");  // Überschrift für die erste Spalte
            case 1:
                return QString("Description");  // Überschrift für die zweite Spalte
            case 2:
                return QString("Due Date");  // Überschrift für die dritte Spalte
            case 3:
                return QString("Assignees");  // Überschrift für die vierte
            case 4:
                return QString("State");
            case 5:
                return QString("Relative Due");
            default:
                return QVariant();  // Für ungültige Spalten keine Überschrift zurückgeben
            }
        }
        return QVariant();  // Für andere Rollen oder Ausrichtungen keine Überschrift zurückgeben
    }

    int getRow() {
        return 42;
    }

private:
    // Die Liste der Aufgaben, die im Modell gespeichert werden.
    QVector<Task> m_tasks;
};

#endif // TASKTABLEMODEL_H
