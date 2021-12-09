# Пример хранения схем

dbname#schemename#
table1{name-type, name-type, name-type}
table2{name-type, name2-type, name3-type}


# Пример хранения таблиц

---Db
    |
   data--|
    |    |
    |    Schemes----[Scheme1, Scheme2]
    |    |
    |    |
    |    Tables--Table1---[Row1, Row2,...]
    |        |
    |        |
    |        |
    |        |-----Table2---[Row1, Row2,...]
    |
    |
    |
    |
    meta--|
    |     |
    |     Schemes----[Schema1_meta_data, Schema2_meta_data,...]
    |     |
    |     |
    |     Tables-----[Table1_meta_data, Table2_meta_data,...]
    |
          
