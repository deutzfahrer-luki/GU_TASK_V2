// TaskTableModel.h
#ifndef TASKTABLEMODEL_H
#define TASKTABLEMODEL_H

#include <QAbstractTableModel>
#include "model/task.h"
#include "util/date.h"


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
        return 4;  // 4 Spalten: ID, Beschreibung, Fälligkeitsdatum, Zugewiesene
    }

    // Gibt die Daten für eine bestimmte Zelle zurück, basierend auf Zeile und Spalte.
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override {
        // Überprüft, ob der Index gültig ist und ob die Daten angezeigt werden sollen (DisplayRole).
        if (!index.isValid() || role != Qt::DisplayRole) {
            return QVariant();  // Keine Daten zurückgeben, wenn die Bedingung nicht erfüllt ist
        }

        // Holt die Aufgabe für die aktuelle Zeile
        const Task &task = m_tasks[index.row()];
        Date Datum(2024,12,24);

        // Gibt die Daten basierend auf der Spalte zurück
        switch (index.column()) {
        case 0:
            return QString::fromStdString(std::to_string(task.getId()));   // Spalte 0: Die ID der Aufgabe
        case 1:
            return QString::fromStdString(task.getDescription());  // Spalte 1: Die Beschreibung der Aufgabe
        case 2:
            return QString::fromStdString(task.getDue());  // Spalte 2: Das Fälligkeitsdatum der Aufgabe
        case 3:
            return QString::fromStdString("42");  // Spalte 3: Die zugewiesenen Personen als kommagetrennte Liste
        default:
            return QVariant();  // Für ungültige Spalten keine Daten zurückgeben
        }
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
                return QString("Assignees");  // Überschrift für die vierte Spalte
            default:
                return QVariant();  // Für ungültige Spalten keine Überschrift zurückgeben
            }
        }
        return QVariant();  // Für andere Rollen oder Ausrichtungen keine Überschrift zurückgeben
    }

private:
    // Die Liste der Aufgaben, die im Modell gespeichert werden.
    QVector<Task> m_tasks;
};

#endif // TASKTABLEMODEL_H
