Оригинальному corewar неважно как называется файл чемпиона

требуется лишь чтобы  в названии файло присутсвовало .cor

Имя игрока считывается из файла







.cor = 
множество байтов, представленных в шестнадцатеричной системе 
исчисления. И именно такой байт-код будет выполнять виртуальная 
машина. 

.s --> просмотреть можно здесь: https://hexed.it/ или прямо в 
 vs_code c помощью расширения:
https://marketplace.visualstudio.com/items?itemName=qiaojie.
binary-viewer

Каретка это процесс, выполняющий операцию, на которой стоит.

В каретке есть:
* PC (Program Counter) - содержит позицию каретки.
* Регистры
* Флаг carry
* Номер цикла

Allowed f()
◦ open
◦ read
◦ lseek
◦ write
◦ close
◦ malloc 
◦ realloc 
◦ free
◦ perror
◦ strerror 
◦ exit

Какие флаги нужно обрабатывать?

Порядок игроков, а точнее порядок назначения идентификационных номеров, можно изменить с помощью флага -n.
-n number sets the number of the next player. If non-existent, the player will have the next available number in the order of the parameters.
---------------
-dump nbr_cyclesat the end of nbr_cycles of executions, dump the memory on the standard outputand quit the game. The memory must be dumped in the hexadecimal format with32 octets per line. Флаг получает номер цикла, после выполнения которого необходимо вывести состояние памяти на экран и прекратить работу программы corewar