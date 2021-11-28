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
   Logger:
      fields:
      commands:
         log();
      queries:
         get_log_status();
   ``` 

6. ```
   FileHandler:
      fields:
      comands:
         open(filename);
         read(filename);
         write(filename, needle);
      queries:
         get_open_status();
         get_read_status();
         get_write_status();
   ```

7. ```
   Table:
      fields:
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

8. ```
   Row:
     fields:
       T value;
     commands:
        setValue();
     queries:
        getValue();
        get_setValue_status();
   ```

## Продолжаем уточнение формальных спцификаций АТД, подробно и развернуто определяем классы в терминах запросов команд и ограничений.
