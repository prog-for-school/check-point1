// ==========================================================
//  SERVER BREAKER 2077: ШАБЛОН
//  Ты хакер. Взломай три сервера, пока Глаз не заметил тебя.
//
//  Что делать:
//    1. Найди в файле 5 мест с пометкой TODO (все в playLevel).
//    2. Делай их ПО ПОРЯДКУ. После каждого собирай и запускай:
//         g++ -std=c++17 main.cpp -o main
//    3. Если игра зависла или спамит текстом: Ctrl + C.
//    4. Когда игра работает, переходи к ТВОРЧЕСТВУ (3 места ниже).
//
//  Всё остальное (рисунок Глаза, выбор слов, уровни) уже готово.
// ==========================================================
#include <iostream>
#include <cstdlib>   // rand, srand
#include <ctime>     // time
#include <string>    // string
#include <cctype>    // tolower
using namespace std;

const int MAX_ERRORS = 6;   // на 6-й ошибке тебя замечают
const int LEVELS = 3;       // сколько серверов надо взломать

// ТВОРЧЕСТВО 1: замени слова на свои (минимум 10).
// Только английские строчные буквы. Тема любая: игры, мемы, школа.
const string WORDS[] = {
    "pointer", "compiler", "variable", "keyboard", "network",
    "firewall", "function", "internet", "password", "algorithm"
};
const int WORDS_COUNT = sizeof(WORDS) / sizeof(WORDS[0]);  // считается сам

// Глаз охраны: 7 кадров (0 ошибок ... 6 ошибок).
// Каждый кадр это обычная строка в "сыром" виде R"( ... )",
// так что рисуй прямо в коде, как в блокноте.
// ТВОРЧЕСТВО 2: перерисуй кадры или придумай своего стража.
// Кадров должно остаться 7, и в каждом одинаковая высота.
const char* EYE[MAX_ERRORS + 1] = {
    // 0: глаз закрыт
    R"(




   -----------------------------------------




)",
    // 1: щёлочка
    R"(



               _________________
   <----_______|               |_______---->
               '''''''''''''''''



)",
    // 2: приоткрылся
    R"(



       ___------'''''''''''''''------___
   <-__        |               |        __->
       '''------_______________------'''



)",
    // 3: открывается
    R"(


            ___-----------------___
      _---''   |               |   ''---_
   <__         |       o       |         __>
      '---__   |               |   __---'
            '''-----------------'''


)",
    // 4: почти открыт
    R"(

               ___-----------___
         _---'' /             \ ''---_
     _--'      |               |      '--_
   <_          |       o       |          _>
     '--_      |               |      _--'
         '---__ \             / __---'
               '''-----------'''

)",
    // 5: широко открыт
    R"(
                    _______
            _----'''       '''----_
        _--'    /             \    '--_
     _-'       |               |       '-_
   <_          |       o       |          _>
     '-_       |               |       _-'
        '--_    \             /    _--'
            '----___       ___----'
                    '''''''
)",
    // 6: ЗАМЕТИЛИ
    R"(
                __-----------__
           _--'' _-'       '-_ ''--_
       _--'     /             \     '--_
     -'        |               |        '-
   <_          |       o       |          _>
     -_        |               |        _-
       '--_     \             /     _--'
           '--__ '-_       _-' __--'
                ''-----------''
)"
};

// Надпись под глазом (как стелс-индикатор в играх)
const char* STATUS[MAX_ERRORS + 1] = {
    "HIDDEN", "HIDDEN", "CAUTION", "CAUTION", "CAUTION!", "ALMOST SPOTTED", "DETECTED"
};

void drawEye(int errors) {
    cout << EYE[errors];
    cout << "\n                  [ " << STATUS[errors] << " ]\n";
}

// Один уровень: возвращает true, если пароль взломан
bool playLevel(const string& word) {
    int len = word.length();

    // Маска слова: "_ _ _ _". Изначально одни подчёркивания
    string mask(len, '_');

    bool tried[26] = { false };  // какие буквы уже вводили (a = 0, b = 1, ...)

    // TODO 1: заведи две переменные:
    //   errors: сколько ошибок сделано (сначала 0)
    //   won:    угадано ли слово целиком (сначала false)
    // Подумай, какой тип нужен каждой: int, bool или char?


    while (errors < MAX_ERRORS && !won) {
        drawEye(errors);
        cout << "\nPassword: ";
        for (int i = 0; i < len; i++) {
            cout << mask[i] << ' ';
        }
        cout << "\nTries left: " << MAX_ERRORS - errors;
        cout << "\nEnter a letter: ";

        char c;

        // TODO 2: считай букву с клавиатуры в переменную c
        // и сделай её строчной, чтобы 'A' и 'a' были одной буквой.
        // Подсказка: cin >> ...   и функция tolower(...)


        // TODO 3: защита от неправильного ввода
        //   а) c не буква (не между 'a' и 'z'): напиши сообщение и continue
        //   б) букву уже вводили: напиши сообщение и continue
        //   в) иначе отметь её как использованную.
        // Подсказка: tried[c - 'a'] это "ячейка" буквы c.
        //            true значит "уже вводили".


        // TODO 4: ищем букву в слове
        //   Пройди циклом по всем буквам слова word (его длина len).
        //   Если word[i] == c: открой её в маске: mask[i] = c
        //   Если после цикла НИ ОДНА буква не нашлась: это ошибка.
        //   Тогда увеличь errors и напиши игроку, что он промахнулся.
        // Подсказка: заведи bool-флажок "нашли ли хоть одну букву".


        // TODO 5: проверь победу
        //   Если mask стала равна word: won = true.
        // Подсказка: у string можно сравнивать через ==
    }

    if (won) {
        cout << "\n>>> ACCESS GRANTED: " << word << " <<<\n";
    } else {
        drawEye(MAX_ERRORS);
        cout << "\n>>> YOU WERE SPOTTED. The password was: " << word << "\n";
    }

    return won;
}

int main() {
    srand(time(0));

    // ТВОРЧЕСТВО 3: перепиши историю ниже на свою (по-английски).

    cout << "=====================================\n";
    cout << "         SERVER BREAKER 2077\n";
    cout << "=====================================\n";
    cout << "You are a hacker. Tonight you break into\n";
    cout << "the servers of MEGACORP and steal the\n";
    cout << "secret files. Each server is guarded by\n";
    cout << "a password and the Eye: a security\n";
    cout << "scanner that never fully sleeps. Every\n";
    cout << "wrong letter opens it a little wider.\n";
    cout << "Six mistakes and you are DETECTED.\n";
    cout << "Stay hidden. Good luck.\n";

    bool used[WORDS_COUNT] = { false };  // чтобы пароли не повторялись

    for (int level = 1; level <= LEVELS; level++) {
        cout << "\n----- SERVER " << level << " of " << LEVELS << " -----\n";

        // Выбираем случайный пароль, который ещё не использовали

        int index;
        do {
            index = rand() % WORDS_COUNT;
        } while (used[index]);
        used[index] = true;

        if (!playLevel(WORDS[index])) {
            cout << "\nGAME OVER. MEGACORP wins this time.\n";
            return 0;
        }
    }

    cout << "\n*****************************************\n";
    cout << "  ALL SERVERS HACKED. Secret files stolen.\n";
    cout << "  You are a legend. Sleep well, hacker.\n";
    cout << "*****************************************\n";
    return 0;
}
