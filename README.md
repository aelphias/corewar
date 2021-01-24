# corewar

Как пушить в нужную ветку (VM):
git clone https://github.com/aelphias/corewar.git


git branch VM origin/VM. (Это действие создаст локальную ветку VM  и подключит ее к серверной ветке VM)


git checkout VM (это переключит тебя с ветки master на ветку VM,)
git checkout похожа на  cd в bash - переходит на другую ветку, как cd меняет директорию
# Нужно сделать по VM:

0 . раскамментить libft.a (#	@rm -rf $(NAME))

[+]1. назначать порядковые номера игрокам с помощью:

-n number sets the number of the next player. If non-existent, the player will have the nextavailable number in the order of the parameters. The last player will have the firstprocess in the order of execution.

[ ]2. проверитть на сигфолты

[ ]3. Сделать проверку на типы аргументов: если аргумент не T_DIR, T_REG, T_IND, шагаем на место после операции

[+]4. op_live дописать проверку того что id игрока существует

# В целом:
1. Мейкфайлы

2. Подвести код к норме

3. Проверить на leaks

4. Отттестить

5. Залить в репозиторий

6. Найти людей и записаться на проверки

7. Защитить

 #TESTS
Тестируем и записываем:
 https://docs.google.com/spreadsheets/d/1E21lOwIcS1PcFKoMY4xsvl0rVSb48lg4JJHWoKvhXP0/edit?usp=sharing

 --
 Тесты не наши:
 Инструкции: https://github.com/rizky/corewar/tree/unit-tests
 зайди в каталог checker_unit и выполни: make tests_vm_dump
 
