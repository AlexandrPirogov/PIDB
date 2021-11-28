# Классы поведения


## Создание формальных спецификаций АТД, выделяем абстрактные, частично реализованные классы и увязываем их в иерархию

1. ```
   Console:
      fields:
         string command;   
      commands:
         //Pre-condtion: none
         //Post-condition: Console contains new commands and sends it to Compilers
         readCommand(command);
      queries:
         get_readCommand_status();
         
   ```
2. ```
   Compiler:
      fields:
         Parser syntaxParser;
         Parser semanticParser;
         const int statuses = 0;
         string plan;
      commands:
         //Pre-condition: 
         //Post-condition: Compile create a plan
         compile(query);
      queries:
         getPlan();
         get_compile_status();
       
   
3. ``` 
   Parser:
       fields:
       Tree tree;
       String query;
       commands:
          //Pre-condition: given a string
          //Post-condition: success or failed parsing's results;
          parse(Query);
       queries:
          get_parse_status();
   ```
   ```
   SyntaxParser : Parser
   SemanticParser : Praser
   ```

4. ```
   ExecuteMachine:
       fields:
       commands:
          //Pre-condition: given an plan
          //Post-condition: executed Transaction/Commands
          exec(plan);
       queries:
          getExecPlan();
   ```

5. ```
   ProtocolManager:
      fields:
         Logger log:
        // Recover recover;
      commands:
         //Pre-condition:
         //Pos-condition: logged databases' action
         log();
        // recover();
      queries:
         get_log_status();
         get_recover_status();
   ```

6. ```
   Logger:
      fields:
      commands:
         //Pre-condition:
         //Post-condition: Логи записаны в файл??
         log();
      queries:
         get_log_status();
   ``` 

7. ```
   //Подумать ещё над менеджером ресурсов
   ResourceManager:
      fields:
         FileHandler fileHandler;
      commands:
         serialize();
         deserialize();
      queries:
   ```

7. ```
   //Подумать ещё над Менеджером файлов
   FileHandler:
      fields:
      commands:
         open(filename);
         read(filename);
         write(filename, needle);
      queries:
         get_open_status();
         get_read_status();
         get_write_status();
   ```

8. ```
   Table:
      fields:
         String name;
         Row rows[];
         ResultTable resultTable;
      commands:
         //Pre-condition:
         //Post-condition: currentRow принимает значения соответсвующие строки
         readRow(expression);
      queries:
         getCurrentRow();
         get_readRow_status();
   ```
   ```
   TableCRUD : Table
      fields:
      commands:
         //Pre-condition:
         //Post-condition: добавляем строку в таблицу
         createRow();
         //Pre-condition: дано выражение
         //Post-condition: обновляет строку в таблицу
         updateRow(expression-lambda);
         //Pre-condition: дано выражение
         //Post-condition: удаляет соответсвующие строки из таблицы
         deleteRow(Row);
      queries:
         get_createRow_status();
         get_updateRow_status();
         get_deleteRow_status();
   ```
   ```
   ResultTable : Table
       commands:
          insertRow();
       queries:
          get_insertRow_status();
   ```
   View : Table
   ```

9. ```
   Row:
     fields:
       T value[];
     commands:
        //Pre-condition: дано значение
        //Post-condition: Строка устанавливает значения соответсвующие
        setValue(value);
     queries:
        getValue();
        get_setValue_status();
   ```
10. ```
    Scheme:
       fields:
          string name;
          Table tables[];
       commands:
          //Pre-condition:Дано название таблицы
          //Post-condition: В схему добавлена таблица
          createTable(String Table); 
          //Pre-condition: Дано название таблицы (желательно существующей)
          //Post-condition: Таблица удалена из схемы
          dropTable(String Table);
          //Pre-condition: Дано название существующей таблицы
          //Post-condition: Соответствующая таблица в схеме изменена
          alterTable(String Table);
       queries:
           get_create_status();
           get_drop_status();
           get_alter_status();
     ```
11.  ```
     Tree:
        fields:
           Node node;
        commands:
           //Pre-condition: Дана нода
           //Post-condition: Добавлена новая нода
           addNode(Node);
           //Pre-condition: Дана нода для удаления
           //Post-condition: Удалена нода из дерева
           deleteNode(Node);
           //Pre-condition:
           //Post-condition: ставит статус об успешном парсинге.
           travel();
        queries:
           get_add_status();
           get_delete_status();
           get_travel_status();
    ```
    ```
    SelectTree : Tree
    InsertTree : Tree
    UpdateTree : Tree
     ```

## Продолжаем уточнение формальных спцификаций АТД, подробно и развернуто определяем классы в терминах запросов команд и ограничений.
