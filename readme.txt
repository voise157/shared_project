Приветствуем...
Структура проекта состоит из модулей делящих проект
на конкретные задачи, часть из них не зависима от
других воовсе.
draw.py - отвечает за отрисовку происходящего на экране,
тем ней менее меню и действия игрока не его задача,
он должен лишь рисовать мир относительно камеры.
gui.py - ответственен за взаимодействие игрока с миром,
меню, управление камерой, машинкой, все здесь.
world.py - ответственен за обработку обьектов,
сам мир и его существование, идет в абсолютных значениях,
что не зависят, ни от игрока, ни от места где работает игра.
определяет поведение обьектов при взаимодействии.
MinPhysBridge.py - мост к движку игры, его обьекты должны
быть основой для всех абсолютных и мира.
objects.py - один файл - все обьекты. должен основываться
на игровом движке, определяя некоторые разнореализуемые
вещи, как они должны быть конкретно.
multiplayer.py - файл который должен быть реализован
в последнюю очередь и даже не обязан существовать.
main.py - главный файл объединяющий все на свете.