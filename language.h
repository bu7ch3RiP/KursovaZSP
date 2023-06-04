#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <QString>

static QString menu_ua[]{"Файл",
                         "Вибір",
                         "Допомога",
                         "Вийти",
                         "Налаштування",
                         "Вибрати всі",
                         "Очистити всі",
                         "Тест для LCD моніторів",
                         "Про програму",
                         "Мова",
                         "Українська",
                         "Англійська"};

static QString menu_en[]{"File",
                         "Selection",
                         "Help",
                         "Exit",
                         "Preferences",
                         "Select all",
                         "Clear all",
                         "Test for LCD monitors",
                         "About",
                         "Language",
                         "Ukranian",
                         "English"};

static QString buttons_ua[]{"Запустити вибрані тести",
                            "Авто-запуск вибраних тестів",
                            "Калібрувальні тести",
                            "Сіткові тести",
                            "Тести кольором",
                            "Тести читабельності"};

static QString buttons_en[]{"Run Selected Tests",
                            "Auto Run Selected Tests",
                            "Calibration tests",
                            "Grid tests",
                            "Color tests",
                            "Reading tests"};

static QString group_box_ua[]{"Калібрувальні тести",
                              "Фокусувальні",
                              "Чорний фон",
                              "Білий фон",
                              "Монотонні",
                              "Градієнт",
                              "Палітри кольорів",
                              "Тексти"};

static QString group_box_en[]{"Calibration tests",
                              "Focus Tests",
                              "Black background",
                              "White background",
                              "Solid Fills",
                              "Gradient Fills",
                              "Color Palettes",
                              "Texts"};

static QString lables_ua[]{"Калібрування РК-дисплея",
                           "Яскравість/контрастність",
                           "Діапазон",
                           "Гамма",
                           "Конвергенція",
                           "Розмір екрану",
                           "Білий візерунок",
                           "Чорний візерунок",
                           "Різкість",
                           "Точки",
                           "Вертикальні лінії",
                           "Горизонтальні лінії",
                           "Біла сітка",
                           "Червона сітка",
                           "Зелена сітка",
                           "Синя сітка",
                           "Пурпурова сітка",
                           "Жовта сітка",
                           "Чорна сітка",
                           "Червона сітка",
                           "Зелена сітка",
                           "Синя сітка",
                           "Пурпурова сітка",
                           "Жовта сітка",
                           "Червоний",
                           "Зелений",
                           "Синій",
                           "Помаранчевий",
                           "Білий",
                           "Чорний",
                           "50% Сірий",
                           "Червоний градієнт",
                           "Зелений градієнт",
                           "Синій градієнт",
                           "Помаранчевий градієнт",
                           "Сірий градієнт",
                           "Палітра кольорів (HSL)",
                           "180 Палітра кольорів (HSL)",
                           "Білий текст на чорному фоні",
                           "Чорний текст на білому фоні",
                           "Червоний текст на синьому фоні",
                           "Синій Текст на зеленому фоні",
                           "Пурпурний Текст на чорному фоні",
                           "Жовтий Текст на синьому фоні"};

static QString lables_en[]{"LCD Calibration",
                           "Brightness/Contrast",
                           "Scope",
                           "Gamma",
                           "Convergence",
                           "Screen Size",
                           "White Pattern",
                           "Black Pattern",
                           "Sharpness",
                           "Dots",
                           "Vertical Lines",
                           "Horizontal Lines",
                           "White Grid",
                           "Red Grid",
                           "Green Grid",
                           "Blue Grid",
                           "Magenta Grid",
                           "Yellow Grid",
                           "Black Grid",
                           "Red Grid",
                           "Green Grid",
                           "Blue Grid",
                           "Magenta Grid",
                           "Yellow Grid",
                           "Red",
                           "Green",
                           "Blue",
                           "Orange",
                           "White",
                           "Black",
                           "50% Gray",
                           "Red Gradient",
                           "Green Gradient",
                           "Blue Gradient",
                           "Orange Gradient",
                           "Gray Gradient",
                           "Color Palette (HSL)",
                           "180 Color Palette (HSL)",
                           "White Text on Black",
                           "Black Text on White",
                           "Red Text on Blue",
                           "Blue Text on Green",
                           "Magenta Text on Black",
                           "Yellow Text on Blue"};

static QString preferences_ua[]{"Загальні налаштування",
                                "Зберегти стан вибору тесту при виході",
                                "Автоматичний режим",
                                "Секунди, протягом яких буде показано\nкожен тестовий екран",
                                "Зберегти",
                                "Налаштування збережено",
                                "Налаштування успішно збережено!",
                                "Гаразд"};

static QString preferences_en[]{"General settings",
                                "Save test selection state on exit",
                                "Automatic mode",
                                "Seconds that each test screen will be shown",
                                "Save",
                                "Settings Saved",
                                "The settings have been saved!",
                                "Ok"};

static QString about_ua[]{
    "Тестування монітора",
    " Інформація про продукт:",
    "    Дана робота виконана в рамках курсового проекту\nз дисципліни: \"Системне "
    "програмне забезпечення\"",
    " Автор роботи:",
    "    Романів Віталій Андрійович, студент групи КІ-35 Націо-\nнального університету \"Львівська "
    "політехніка\" спеціаль-\nності \"Комп'ютерна інженерія\"",
    "Версія: 1.0 beta"};

static QString about_en[]{
    "Monitor Testing",
    " Product information:",
    "    This work was performed within the scope of the course\nproject in the "
    "discipline: \"System Software\"",
    " Author of the work:",
    "    Romaniv Vitalii Andriyovich, student of group KI-35 of the National University\n\"Lviv "
    "Polytechnic\" majoring in Computer Engineering",
    "Version: 1.0 beta"};

static QString title_ua[]{"Тестування монітору", "Про програму", "Налаштування тестування монітору"};

static QString title_en[]{"Monitor testing", "About", "Display testing preferences"};

static QString page_hints_en[]{
    "   On this page, you can find several tests for monitor calibration. "
    "These tests are suitable for both classic (CRT)\nand LCD displays."
    "\n   Move your cursor over a test name to get a description about it, "
    "and to see a small thumbnail about the\ntest screen.",
    "   Grid tests are ideal for checking, and tuning the display geometry, and convergence "
    "settings.",
    "   On this page, you can find several tests to check your computer and monitor your ability "
    "to display colors\nand see dead/stuck pixels on LCD displays.",
    "   On this page, you can find several reading tests. With these tests, you can check your "
    "monitor focus on\nthe whole screen and with different font and background colors."};

static QString page_hints_ua[]{
    "   На цій сторінці ви можете знайти кілька тестів для калібрування монітора. "
    "Ці тести підходять як для\nкласичних (ЕПТ) так і для рідкокристалічних дисплеїв."
    "\n   Наведіть курсор на назву тесту, щоб отримати його опис "
    "та побачити невелику мініатюру екрана тесту.",
    "   Тести сітки ідеально підходять для перевірки та налаштування геометрії дисплея і "
    "збіжності\nналаштувань.",
    "   На цій сторінці ви можете знайти декілька тестів для перевірки вашого комп'ютера та "
    "моніторингу\nвашої здатності відображати кольори та бачити мертві/биті пікселі на "
    "РК-дисплеях.",
    "   На цій сторінці ви можете знайти декілька тестів на читання. За допомогою цих тестів ви"
    " можете\nперевірити фокус монітора на всьому екрані та з різними кольорами шрифту і тла."};

static QString read_en_en{
    "   With this test, you can check your monitor's focus on the whole screen. Text reading "
    "is especially important\nfor all kinds of desktop work like word processing and web surfing, "
    "where clear, sharp letters relax the eyes."};

static QString read_en_ua{
    "   За допомогою цього тесту ви можете перевірити фокусування вашого монітора на всьому "
    "екрані.\n   Читання тексту особливо важливе для всіх видів настільної роботи, таких як "
    "обробка текстів і веб-\nсерфінг, де чіткі, різкі літери розслаблюють очі"};

#endif // LANGUAGE_H
