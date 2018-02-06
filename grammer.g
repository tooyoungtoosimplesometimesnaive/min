
statement : '(' expressions ')' ;
expressions : expression ('\s' expression)* ;
expression: name | statement ;
name: ('a'...'z'|'A'...'Z')+ ;
