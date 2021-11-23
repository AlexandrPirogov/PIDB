# PIDB

## Система управления базой данных.

Данная СУБД будет подобием модели реляционной СУБД. Для работы с данными будут созданы отношения (таблица), содержащая атрибуты.

___

Наиболее обшие сущности на данный момент:
1. Компилятор -- транслирует запрос в план
2. Менеджер -- занимается управлением различных компонентов
3. Отношение -- Компонент, отражающий сущность хранимых данных 
4. Кортеж -- Содержит непосредственно данные 
5. Логгер -- Компонент ответственный за протоколирование
6. Парсер -- Выполняет семантический и синтаксический разбор запроса
7. Исполняющая машина -- сущность, несет ответственность за исполнение запросовю
8. Буфферы -- Участки, куда может быть помещено содержимое дисковых блоков

Получается следующая схема:

Пользователь вводит в консоль запрос, состоящий из команд. 
Запрос направляется в компилятор запросов, который парсит запрос и, в случае успешного парсинга, выдает план исполняющей машине.
Исполняющая машина взаимодействует с менеджером протоколирования, для логгирования, ~~и менеджером ресурсов~~ .
Далее ~~, при успешном взаимодействии с менеджером ресурсов,~~ исполняется запрос и субд работает с отношениями и их содержимым.

## Границы разрабатываемой системы
   1. Будет включена возможность запись, чтение, хранение, удаление данных.
   2. СУБД будет состоять из следующих подсистем: система менеджеров, компиляторов, носитель данных
   3. Пользователские метафоры: консоль на первое время; Визуальный интерфейс, аля DBeaver, например, поиск информации по кнопке, вывести список отншений, посмотреть DLL отношения.... 
   4. Функциональность: Хранение, изменениие и работа с данными (поиск, сортировка и т.д)
   5. Библиотеки повторного использования: Библиотека для работы с потоками cin, cout; vector, algorith... Для создания GUI - QT cpp

## Основные классы анализа
 
   - Compiler - АТД с методами set(query), getPlan(). Забирает запрос и отдаёт план запроса 
   - Logger - АТД с методами log(). Записывает логи в...
   - ExecMachine - АТД, с методами execute(plan), create(Table, Row), delete(Table, Row), read(Table, Row), update(Table, Row)
  
   - Table - АТД, с методами read(row). Хранит в себе кортежи. 
   - ~~ CRUDTable - АТД,с методами read(row), create(row), delete(row), update(row) ~~ `upd 21-11-23`
   - View - АТД, с методами read(row).

   - Row - АТД, с методами read(column).Считывает значение определенного поля
   - ~~ CRUDRow - АТД, с методами read(column), update(column), delete(column), set(column). ~~ `upd 21-11-23`

   - Column - АТД, с методами set(value), getValue(). Хранит значение

   - Parser - АТД, с методами parse(query).
 - ~~ ParserDDL - АТД, с методами parse(query). ~~ `upd 21-11-23`
 - ~~ ParserQuery - АТД, с мтеодами parse(query). ~~ `upd 21-11-23`
   
   - BufferManager - АТД, с методами alloc(),  
   - DiskHandler - АТД, с методом getSize(), getFreeSize(), Alloc(). Аналог вторичного устройства (носителя данных). Изучить принципы хранения информации.
   - DiskManager - АТД, с методами readDisk(Disk), getLocation().

   - TransactionManager - АТД, с методами
   - Transaction - АТД, с методами notifyStart(TransactionManager), notifyEnd(TransactionManager) 
   - Console - АТД, с методами read(), exec()
   -  
----------------------------------

   1. Console -> Вводят команду (запрос) в консоль. Консоль считывает и выполняет команду.
   2. Compiler -> В зависимости от запроса, отдаёт запрос парсеру, на синтаксическую и семантическую проверку. При успешном парсинге, выдает план исполняющей машине
   3. ExecMachine -> Получает план запроса. Направляет группу запросов менеджеру ресурсов, который "осведомлен" об особенностях размещения информации в файлах данных
(data files).
   4. Запросы транслируются в адреса страниц и переслыются менеджеру буфероф.
   5. BufferManager -> Обращается к соответствующим порциям данных с последующим переносом данных в буферы, расположенных в оперативной памяти, и наоборот. Чтобы обратиться к данным на диске, менеджер буфферов обращается к менеджеру хранения данных, решающий возложенные на него задачи. Ответственнен за разбиение доступной оперативной памяти на участки-страицы, куда будет помещено содержимое дисковых блоков.
   6. Менеджер хранения данных определяет местоположение хранимых данных на диске.
-----------------------------------

   1. Команды оформляются в виде транзакций.
   2. Менеджер транзакций воспринимает от приложения команды тразакции, которые свидетельствуют от начале и завершении транзакции. 
   3. Процессор транзакций выполняет следующее:
       1. Протоколирование

------------------------------------


## Классы реализаций

   - Для парсинга запросов потребуется структура данных деревья, для синтаксического разбора.
   - Для хранения организации "директории БД" потребуются деревья, но, возможно, с особым хранением объектов (будет хранить не просто значение, а возможно список файлов)
   - Структура данных Buffers, для быстрого обмена "страницами" между оперативной памятью и вторичным устройством
