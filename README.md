# corewar

Как пушить в нужную ветку (VM):
git clone https://github.com/aelphias/corewar.git


git branch VM origin/VM. (Это действие создаст локальную ветку VM  и подключит ее к серверной ветке VM)


git checkout VM (это переключит тебя с ветки master на ветку VM,)
git checkout похожа на  cd в bash - переходит на другую ветку, как cd меняет директорию


Готово:
1. Ассемблер (частично, но все же следует кое-что подправить)
2. Дизассемблер (частично)

Нужно сделать:

По парсеру:
1. назначать порядковые номера игрокам с помощью:
-n number sets the number of the next player. If non-existent, the player will have the nextavailable number in the order of the parameters. The last player will have the firstprocess in the order of execution.
2. проверитть на сигфолты

 В целом:
1. Виртуальная машина
2. Отттестить
3. Подвести код к норме
4. Мейкфайлы
5. ...
