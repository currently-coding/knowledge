#include <iostream>
#include <limits>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <unordered_map>
#include <map>

class Time
{
private:
    int _hours;
    int _minutes;
    std::string _day;

public:
    Time(std::string day, int hours, int minutes);

    std::string get_date() const;
    std::string get_time() const;
    void set(int hours, int minutes, std::string day);
    int get_hours() const { return _hours; }
    int get_minutes() const { return _minutes; }
    std::string get_day() const { return _day; }
};

Time::Time(std::string day, int hours, int minutes) : _hours(hours), _minutes(minutes), _day(day) {}

void Time::set(int hours, int minutes, std::string day)
{
    _hours = hours;
    _minutes = minutes;
    _day = day;
}

std::string Time::get_date() const
{
    std::string result = _day + ", " + std::to_string(_hours) + ":" + std::to_string(_minutes);
    return result;
}

std::string Time::get_time() const
{
    std::string result = std::to_string(_hours) + ":" + std::to_string(_minutes);
    return result;
}

// END-OF-TIME - - - - - - - - - - - - - - - - - - - - - - - - -

class Entry
{
public:
    std::string professor;
    std::string abbreviation;
    std::string name;
    std::string typ;
    Time date;
    static int max_abbreviation_length;
    static std::unordered_map<std::string, int> day_order;

    std::map<std::string, std::vector<std::string>> _entry;

    Entry(Time time, std::string abbreviation, std::string name, std::string typ, std::string professor);

    bool operator==(const Entry &other) const
    {
        return abbreviation == other.abbreviation;
    }
    bool operator<(const Entry &other) const;

    void display();
};

std::unordered_map<std::string, int> Entry::day_order = {
    {"Monday", 1},
    {"Tuesday", 2},
    {"Wednesday", 3},
    {"Thursday", 4},
    {"Friday", 5},
    {"Saturday", 6},
    {"Sunday", 7},
};

int Entry::max_abbreviation_length = 0;

Entry::Entry(Time time, std::string abbreviation, std::string name, std::string typ, std::string professor) : date(time), abbreviation(abbreviation), name(name), typ(typ), professor(professor)
{
    if (abbreviation.size() > max_abbreviation_length)
    {
        max_abbreviation_length = abbreviation.size();
    }
}

bool Entry::operator<(const Entry &other) const
{
    if (day_order.at(date.get_day()) == day_order.at(other.date.get_day()))
    {
        if (date.get_hours() == other.date.get_hours())
        {
            return date.get_minutes() < other.date.get_minutes();
        }
        else
        {
            return date.get_hours() < other.date.get_hours();
        }
    }
    else
    {
        return day_order.at(date.get_day()) < day_order.at(other.date.get_day());
    }
}

void Entry::display()
{
    std::cout << "Entry: " << std::endl;
    std::cout << "Kuerzel: " << abbreviation << std::endl;
    std::cout << "Professor: " << professor << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Typ: " << typ << std::endl;
    std::cout << "Time: " << date.get_date();
    std::cout << std::endl;
}

// END-OF-ENTRY - - - - - - - - - - - - - - - - - - - - - - - - -

Entry create_entry()
{
    bool no_errors = true;
    std::string day, abbreviation, name, typ, professor;
    int hours, minutes;
    do
    {

        std::cout << "Enter day: ";
        std::cin >> day;
        std::cout << "Enter hours: ";
        std::cin >> hours;
        std::cout << "Enter minutes: ";
        std::cin >> minutes;
        if (minutes % 15 != 0)
        {
            std::cout << "Invalid start of lesson. " << std::endl;
            std::cout << "\nRestarting entry creation." << std::endl;
            no_errors = false;
            continue;
        }
        std::cout << "Enter abbreviation: ";
        std::cin >> abbreviation;
        std::cout << "Enter name: ";
        std::cin >> name;
        std::cout << "Enter type: ";
        std::cin >> typ;
        std::cout << "Enter professor: ";
        std::cin >> professor;

    } while (!no_errors);

    Time time(day, hours, minutes);
    Entry entry(time, abbreviation, name, typ, professor);
    return entry;
}

class Schedule
{
private:
    std::vector<Entry> _entries;
    std::vector<std::pair<int, std::string>> _menu;

public:
    Schedule(std::vector<Entry> entries);

    Entry search_entry(std::string abbreviation); // input: Kuerzel -> Entry

    void menu();
    void display();
    void show_details();
    void add_entry(Entry entry);
    void remove_entry(Entry entry);
    void import_file(std::string filename); // overrides all existing data
    void export_file(std::string filename);
    void exit();
};

Schedule::Schedule(std::vector<Entry> entries) : _entries(entries)
{
    _menu = {
        {1, "Stundeplan anzeigen"},
        {2, "Details zu Lehrveranstaltungen anzeigen"},
        {3, "Eintrag anlegen"},
        {4, "Eintrag loeschen"},
        {5, "Stundenplan importieren"},
        {6, "Stundenplan loeschen"},
    };
}

void Schedule::display()
{
    using namespace std;

    const vector<string> days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    const int num_days = days.size();
    const int slots_per_hour = 4; // 4 slots per hour (15-minute intervals)

    // Determine the earliest and latest times in the schedule
    int earliest_hour = 24, latest_hour = 0;
    for (const auto &entry : _entries)
    {
        earliest_hour = min(earliest_hour, entry.date.get_hours());
        latest_hour = max(latest_hour, entry.date.get_hours() + 1); // +1 to account for the last hour being occupied
    }

    // Print the header row
    cout << setw(10) << "Time";
    for (const auto &day : days)
    {
        cout << setw(Entry::max_abbreviation_length + 2) << day.substr(0, 3);
    }
    cout << endl;

    // Iterate over each 15-minute slot
    for (int hour = earliest_hour; hour <= latest_hour; ++hour)
    {
        for (int slot = 0; slot < slots_per_hour; ++slot)
        {
            int minutes = slot * 15;
            stringstream time_slot;
            time_slot << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minutes;
            cout << setw(10) << time_slot.str();

            for (const auto &day : days)
            {
                bool found = false;
                for (const auto &entry : _entries)
                {
                    if (entry.date.get_day() == day && entry.date.get_hours() == hour && entry.date.get_minutes() == minutes)
                    {
                        cout << setw(Entry::max_abbreviation_length + 2) << entry.abbreviation;
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    cout << setw(Entry::max_abbreviation_length + 2) << " ";
                }
            }
            cout << endl;
        }
    }
}

void Schedule::show_details()
{
    std::string kuerzel;
    std::cout << "Kuerzel: " << std::flush;
    std::cin >> kuerzel;
    for (auto &element : _entries)
    {
        if (element.abbreviation == kuerzel)
        {
            element.display();
        }
    }
}

void Schedule::add_entry(Entry entry)
{
    std::cout << "{" << std::endl;

    auto it = std::lower_bound(_entries.begin(), _entries.end(), entry);
    _entries.insert(it, entry);
    std::cout << "Added entry: " << entry.abbreviation << std::endl;
    std::cout << "}" << std::endl;
}

void Schedule::remove_entry(Entry entry)
{
    std::cout << "{" << std::endl;
    std::cout << "Removing entry" << std::endl;
    auto it = std::find_if(_entries.begin(), _entries.end(), [&](const Entry &e)
                           { return e.abbreviation == entry.abbreviation; });

    if (it != _entries.end())
    {
        _entries.erase(it);
        std::cout << "Entry removed: " << entry.abbreviation << std::endl;
    }
    else
    {
        std::cout << "Entry not found: " << entry.abbreviation << std::endl;
    }
    std::cout << "}" << std::endl;
}

void Schedule::export_file(std::string filename)
{
    std::ofstream out_file(filename);

    // write all relevant data to a file - seperated by ;

    out_file.close();
}

void Schedule::import_file(std::string filename)
{
    std::ifstream in_file(filename);

    // read from said file and write everything you read in sequence into the respective variables - seperated by ;

    in_file.close();
}

Entry Schedule::search_entry(std::string abbreviation)
{
    for (const auto &it : _entries)
    {
        if (it.abbreviation == abbreviation)
        {
            return it;
        }
    }
    std::cerr << "Unable to find entry! Schedule::search_entry()" << std::endl;
    return Entry(Time("Unknwon", -1, -1), "", "", "", ""); // TODO: find a better way to signal unsuccessful search
}

void Schedule::menu()
{
    for (const auto &elem : _menu)
    {
        std::cout << elem.first << " " << elem.second << std::endl;
    }
    int option(1);
    std::cout << "\nChoice: " << std::endl;
    std::cin >> option;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << std::endl;

    switch (option)
    {
    case 1:
        display();
        break;
    case 3:
    {
        Entry entry = create_entry();
        add_entry(entry);
        break;
    }
    case 4:
    {
        std::string input;
        std::cout << "Kuerzel: " << std::endl;
        std::cin >> input;
        Entry entry = search_entry(input);
        remove_entry(entry);
        break;
    }
    case 2:
        show_details();
        break;
    case 6:
        export_file("schedule_export.txt");
        break;
    case 5:
        import_file("schedule_import.txt");
        break;
    default:
        exit();
        break;
    }
}

void Schedule::exit()
{
    std::cout << "Quitting..." << std::endl;
}

// END-OF-SCHEDULE - - - - - - - - - - - - - - - - - - - - -

int main(int argc, char const *argv[])
{
    int option(1);
    Schedule schedule({});

    while (0 < option && option < 7)
    {
        schedule.menu();
    }
    return 0;
}