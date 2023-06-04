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

static QString color_test_en[]{
    "   This solid red screen is ideal to check the color uniformity of your monitor. LCD users "
    "are also able to check\nthe display area for dead (always dark) red sub-pixels. You should "
    "degauss your classic (CRT) display before\nthis test. Magnetic fields (e.g. speakers) near "
    "the monitor can produce color distortions.\n   Small imperfections are common in LCD "
    "monitors, please refer to your user's manual for the manufacturer's dead\npixel policy.",

    "   This solid green screen is ideal to check the color uniformity of your monitor. LCD users "
    "are also able to\ncheck the display area for dead (always dark) green sub-pixels. You should "
    "degauss your classic (CRT)\ndisplay before this test. Magnetic fields (e.g. speakers) "
    "near the monitor can produce color distortions.\n   Small imperfections are common in LCD "
    "monitors, please refer to your user's manual for the\nmanufacturer's dead pixel policy.",

    "   This solid blue screen is ideal to check the color uniformity of your monitor. LCD users "
    "are also able to\ncheck the display area for dead (always dark) blue sub-pixels. You should "
    "degauss your classic (CRT)\ndisplay before this test. Magnetic fields (e.g. speakers) near "
    "the monitor can produce color distortions.\n   Small imperfections are common in LCD "
    "monitors, please refer to your user's manual for the\nmanufacturer's dead pixel policy.",

    "   This solid orange screen is ideal to check the color uniformity of your monitor. You "
    "should degauss your\nclassic (CRT) display before this test. Magnetic fields (e.g. speakers) "
    "near the monitor can produce\ncolor distortions.",

    "   Completely white screen for checking the backlight brightness and uniformity of the LCD "
    "monitor and is\nalso good to find dead (always dark) pixels.\n   Small imperfections are "
    "common in LCD monitors, please refer to your user's manual for the\nmanufacturer's dead pixel "
    "policy.",

    "   Completely black screen for checking the backlight brightness and uniformity of the LCD "
    "monitor and is\nalso good to find dead (always dark) pixels.\n   Small imperfections are "
    "common in LCD monitors, please refer to your user's manual for the\nmanufacturer's dead pixel "
    "policy.",

    "   You should degauss your classic (CRT) display before this test. Magnetic fields (e.g. "
    "speakers) near the\nmonitor can produce color distortions.\n   Small imperfections are common "
    "in LCD monitors, please refer to your user's manual for the manufacturer's\ndead pixel "
    "policy.",

    "   Gradient fill is an ideal test to check the monitor's ability to display a smooth color "
    "transition from black to\nred. It is recommended to run this test in True color mode. Several "
    "color management solutions can cause\nsome roughness in the color transition, this is a "
    "normal "
    "phenomenon.",

    "   Gradient fill is an ideal test to check the monitor's ability to display a smooth color "
    "transition from black to\ngreen. It is recommended to run this test in True color mode. "
    "Several color management solutions can cause\nsome roughness in the color transition, this is "
    "a normal phenomenon.",

    "   Gradient fill is an ideal test to check the monitor's ability to display a smooth color "
    "transition from black to\nblue. It is recommended to run this test in True color mode. "
    "Several "
    "color management solutions can cause\nsome roughness in the color transition, this is a "
    "normal "
    "phenomenon.",

    "   Gradient fill is an ideal test to check the monitor's ability to display a smooth color "
    "transition from black to\norange. It is recommended to run this test in True color mode. "
    "Several color management solutions can cause\nsome roughness in the color transition, this is "
    "a normal phenomenon.",

    "   Gradient fill is an ideal test to check the monitor's ability to display a smooth color "
    "transition from black to\ngray. It is recommended to run this test in True color mode. "
    "Several "
    "color management solutions can cause\nsome roughness in the color transition, this is a "
    "normal "
    "phenomenon.",

    "Hue Saturation Lightness palette.",

    "Hue Saturation Lightness palette roteted by 180*."};

static QString color_test_ua[]{
    "   Цей суцільно червоний екран ідеально підходить для перевірки однорідності кольорів вашого\n"
    "монітора. Користувачі рідкокристалічних моніторів також можуть перевірити область "
    "відображення на\nнаявність мертвих (завжди темних) червоних субпікселів.\n   Невеликі дефекти "
    "характерні для РК-моніторів, будь ласка, зверніться до посібника користувача, щоб\nдізнатися "
    "про політику виробника щодо \"мертвих пікселів\".",

    "   Цей суцільний зелений екран ідеально підходить для перевірки однорідності кольорів вашого\n"
    "монітора. Користувачі рідкокристалічних дисплеїв також можуть перевірити область відображення "
    "на\nнаявність мертвих (завжди темних) зелених субпікселів.\n   Невеликі дефекти характерні "
    "для РК-моніторів, будь ласка, зверніться до посібника користувача, щоб\nдізнатися про "
    "політику виробника щодо \"мертвих пікселів\".",

    "   Цей суцільний синій екран ідеально підходить для перевірки однорідності кольорів вашого\n"
    "монітора. Користувачі рідкокристалічних дисплеїв також можуть перевірити область відображення "
    "на\nнаявність мертвих (завжди темних) синіх субпікселів.\n   Невеликі дефекти характерні для "
    "РК-моніторів, будь "
    "ласка, зверніться до посібника користувача, щоб\nдізнатися про політику виробника щодо "
    "\"мертвих пікселів\".",

    "   Цей суцільний помаранчевий екран ідеально підходить для перевірки однорідності кольорів "
    "вашого\nмонітора.",

    "   Повністю білий екран для перевірки яскравості та рівномірності підсвічування РК-монітора, "
    "а також\nдля пошуку \"мертвих\"(завжди темних) пікселів.\n   Невеликі дефекти є звичайним "
    "явищем для РК-моніторів, будь ласка, зверніться до посібника\nкористувача для ознайомлення з "
    "політикою виробника щодо мертвих пікселів.",

    "   Повністю чорний екран для перевірки яскравості та рівномірності підсвічування РК-монітора, "
    "а також\nдля пошуку \"мертвих\" (завжди темних) пікселів.\n   Невеликі дефекти є звичайним "
    "явищем для РК-моніторів, будь ласка, зверніться до посібника\nкористувача для ознайомлення з "
    "політикою виробника щодо мертвих пікселів.",

    "   Перед проведенням цього тесту слід розмагнітити класичний (ЕПТ) монітор. Магнітні поля "
    "(наприклад,\nдинаміки) поблизу монітора можуть спричинити спотворення кольорів.\n   Невеликі "
    "дефекти є звичайним явищем для РК-моніторів, будь ласка, зверніться до посібника\nкористувача "
    "для ознайомлення з політикою виробника щодо мертвих пікселів.",

    "   Градієнтна заливка - ідеальний тест для перевірки здатності монітора відображати плавний "
    "перехід\nвід чорного до червоного кольору. Рекомендується запускати цей тест у режимі "
    "\"Справжній колір\".\nДеякі рішення для керування кольором можуть спричинити деяку шорсткість "
    "у переході кольорів, це\nнормальне явище.",

    "   Градієнтна заливка - ідеальний тест для перевірки здатності монітора відображати плавний "
    "перехід\nвід чорного до зеленого кольору. Рекомендується запускати цей тест у режимі "
    "\"Справжній колір\".\nДеякі рішення для керування кольором можуть спричинити деяку шорсткість "
    "у переході кольорів, це\nнормальне явище.",

    "   Градієнтна заливка - ідеальний тест для перевірки здатності монітора відображати плавний "
    "перехід\nвід чорного до синього кольору. Рекомендується запускати цей тест у режимі "
    "\"Справжній колір\".\nДеякі рішення для керування кольором можуть спричинити деяку шорсткість "
    "у переході кольорів, це\nнормальне явище.",

    "   Градієнтна заливка - ідеальний тест для перевірки здатності монітора відображати плавний "
    "перехід\nвід чорного до оранжевого кольору. Рекомендується запускати цей тест у режимі "
    "\"Справжній колір\".\nДеякі рішення для керування кольором можуть спричинити деяку шорсткість "
    "у переході кольорів, це\nнормальне явище.",

    "   Градієнтна заливка - ідеальний тест для перевірки здатності монітора відображати плавний "
    "перехід\nвід чорного до сірого кольору. Рекомендується запускати цей тест у режимі "
    "\"Справжній "
    "колір\".\nДеякі рішення для керування кольором можуть спричинити деяку шорсткість у переході "
    "кольорів, це\nнормальне явище.",

    "Палітра насичиних та легких відтінків.",

    "Палітра насичиних та легких відтінків обернена на 180 градусів."};

static QString calibration_test_en[]{
    "   Use this test screen to perform automatic screen calibration. LCD panels using digital "
    "(DVI) "
    "connector cables\ndo not require screen adjustments.",

    "   This test screen helps you to select the right values for your display. First of all, set "
    "the "
    "brightness of your\nmonitor to the max, then decrease it until the color around the test "
    "patterns appears black, then adjust the\ncontrast until you are able to see all twenty shades "
    "of gray in both rows.",

    "   Use this test screen to perform basic screen geometry calibration, and to adjust advanced "
    "settings in the\ncase they are available in your monitor configuration menu.",

    "   Bring up your gamma correction controls. Adjust the overall gamma until the model and top "
    "sections of the\ngrey square on the right are the same brightness.",

    "   This calibration test screen is designed for classic (CRT) monitors to check their ability "
    "to "
    "position the\nred, green and blue electron beams accurately.",

    "   The test to calibrate the perfect screen resolution",

    "   Focus is not the only effect that reduces image sharpness. Take also a look at the "
    "convergence and\ndecrease the contrast if necessary. Use the focus test screen to search for "
    "differences between the\ncenter pattern and the corners."};

static QString calibration_test_ua[]{
    "   Використовуйте цей тестовий екран для автоматичного калібрування екрана. РК-панелі,\nщо "
    "використовують кабелі з цифровим (DVI) роз'ємом, не потребують налаштування екрана.",

    "   Цей тестовий екран допоможе вам вибрати правильні значення для вашого дисплея. Перш\nза "
    "все, "
    "встановіть яскравість монітора на максимум, потім зменшуйте її до тих пір, поки\nколір "
    "навколо "
    "тестових зразків не стане чорним, після чого відрегулюйте контрастність до тих пір,\nпоки не "
    "зможете побачити всі двадцять відтінків сірого в обох рядах.",

    "   Використовуйте цей тестовий екран для виконання базового калібрування геометрії екрана, а\n"
    "також для налаштування додаткових параметрів, якщо вони доступні в меню конфігурації "
    "монітора.",

    "   Відкрийте елементи керування гамма-корекції. Налаштуйте загальну гаму так, щоб модель і\n"
    "верхні секції сірого квадрата праворуч мали однакову яскравість.",

    "   Цей тестовий екран калібрування призначений для класичних (ЕПТ) моніторів, щоб перевірити\n"
    "їхню здатність точно позиціонувати червоний, зелений і синій електронні промені.",

    "   Тест для калібрування ідеальної роздільної здатності екрана",

    "   Фокусування - не єдиний ефект, який знижує різкість зображення. Погляньте також на\n"
    "конвергенцію і зменшіть контрастність, якщо це необхідно. Використовуйте екран перевірки\n"
    "фокусування для пошуку відмінностей між центральною частиною зображення і кутами."};

#endif // LANGUAGE_H
