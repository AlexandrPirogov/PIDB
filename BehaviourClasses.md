# Классы поведения


## Создание формальных спецификаций АТД, выделяем абстрактные, частично реализованные классы и увязываем их в иерархию

1. ```
   Console:
      fields:
         
      commands: 
         
      queries:
         
   ```
2. ```
   Compiler:
      fields:
         Parser syntaxParser;
         Parser semanticParser;
         const int statuses = 0;
         string plan;
      commands:
         compile(query)
      queries:
         getPlan();
         get_compile_status();
       
   
3. ``` 
   Parser:
       fields:
       Tree tree;
       String query;
       commands:
          parse();
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
         log();
      queries:
         get_log_status();
   ``` 

7. ```
   ResourceManager:
      fields:
         FileHandler fileHandler;
      commands:
         serialize();
         deserialize();
      queries:
   ```

7. ```
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
         Row currentRow;
      commands:
         readRow(Row);
      queries:
         getCurrentRow();
         get_readRow_status();
   ```
   ```
   TableCRUD : Table
      fields:
      commands:
         createRow(Row);
         updateRow(Row);
         deleteRow(Row);
      queries:
         get_createRow_status();
         get_updateRow_status();
         get_deleteRow_status();
   ```

   ```
   View : Table
   ```

9. ```
   Row:
     fields:
       T value;
     commands:
        setValue();
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
         createTable(Table);
         dropTable(Table);
         alterTable(Table);
      queries:
          get_create_status();
          get_drop_status();
          get_alter_status();
    ```
11. ```
    Tree:
       fields:
          Node node;
       commands:
          addNode();
          deleteNode();
          travel();
       queries:
          get_add_status();
          get_delete_status();
          get_travel_status();
    ```
    SelectTree : Tree
    InsertTree : Tree
    UpdateTree : Tree
        ```

## Продолжаем уточнение формальных спцификаций АТД, подробно и развернуто определяем классы в терминах запросов команд и ограничений.
