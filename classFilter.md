# Отбраковка классов

нa `28-11-18` имеем следующие АТД:

ATDs:

```
Columns:
   T Value;
   commands:
     setValue(value); 
   queries:
      getValue(value);
```
-------------------
```
Row:
   Column columns[];
   commands:
      setValue(Field)
   queries:
      getValue(Field)
```
----------------
```
CrudRow extends Row
```
Отбраковываем `CrudRow`, так как продолжает иерархию
--------------
```
Table:
   Row rows[];
   commands:
      read(row);
   queries:
      get_read_status();
```
------------
```
CRUDTable extends Table:
   commands:
      read(row);
      create(row);
      update(row);
      delete(row);
   queries:
      get_read_status();
      get_create_status();
      get_update_status();
      get_delete_status();
``` 
Отбраковываем `CrudTable`, так как продолжает иерархию
---------------
```
ViewTable extends Table:
```
Отбраковываем `ViewTable`, так как это продолжает иерархи. классов.
--------------
```
Scheme:
   Table tables[];   
   commands:
      createTable();
   queries:
      get_createTable_status();
```
----------
```
QueryParser:
   GrammarTree tree;
   commands:
      parseQuery(Query);
   queries:
      get_parse_status();
```
---------

```
Compiler:
   SyntaxParser syntaxParser;
   SemanticParser semanticParser;
   commands:
      compilerQuery(Query);
   queries:
      get_compile_status();
```

------------------
```
ParserDDL extends Parser 
```
Отбраковываем `ParserDDL`, так как продолжает иерарию классов
--------------

``` 
Transaction:
   Command commands[]
   commands:
      
   queries:
```

-------------------

```
TransactionManager:
   Logger log;
   Transation transactions;
   commands:
      ???
      //rollback();
   queries:
      get_exec_status();
```

-----------


```
Logger:
   commands:
      log();
   query:
      get_log_status();;
```
--------------

```
ExecuteMachine:
   commands:
      executeTransaction(transaction);
   queries:
      get_exec_status();
```

------------------

```
FileManager:
   String path;
   String dbFileName;
   String shemeFileName;
   commands:
      open();
      write();
      read();
   queries: 
      get_open_status();
      get_write_status();
      get_read_status();
```
-----------------

```
FileParser : Parser
```

Отбраковываем, так как продолжает иерархию и выбираем классы-кандидатов исключительно по ТАТД. 
-------------------

```
Console:
   
   commands:
      read();
   queries:
      get_read_status();
```






