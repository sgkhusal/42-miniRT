# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    error_test.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 16:51:25 by sguilher          #+#    #+#              #
#    Updated: 2022/11/29 17:46:10 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

MINIRT_PATH="../miniRT"
SCENES_PATH="../scenes/invalid/"
VALGRIND="valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes"

scene_lists=(
	"invalid_scene_files.txt"
	"invalid_contents.txt"
	"optional.txt"
)

BOLD="\e[1m"
YELLOW="\033[0;33m"
GREY="\033[38;5;244m"
PURPLE="\033[1;35m"
BLUE="\033[1;34m"
LIGHT_BLUE="\033[0;36m"
GREEN="\033[38;5;83m"
GREEN2="\033[38;2;34;183;235m"
RED="\033[38;2;222;56;43m"
PINK="\033[38;5;212m"
END="\033[0m"

if [[ $1 ]]; then
	rm -rf ./valgrind_log
	mkdir ./valgrind_log
else
	rm -rf ./outfiles
	mkdir ./outfiles
fi
NO=$(echo $SCENES_PATH"no_permission.rt")
touch $NO && chmod 000 $NO

printf $GREEN2
if [[ $1 ]]; then
	echo "            ███    ███ ██ ███    ██ ██ ██████  ████████        ";
	echo "            ████  ████ ██ ████   ██ ██ ██   ██    ██           ";
	echo "            ██ ████ ██ ██ ██ ██  ██ ██ ██████     ██           ";
	echo "            ██  ██  ██ ██ ██  ██ ██ ██ ██   ██    ██           ";
	echo "            ██      ██ ██ ██   ████ ██ ██   ██    ██           ";
	echo "                                                               ";
	echo "                                                               ";
	echo "██    ██  █████  ██       ██████  ██████  ██ ███    ██ ██████  ";
	echo "██    ██ ██   ██ ██      ██       ██   ██ ██ ████   ██ ██   ██ ";
	echo "██    ██ ███████ ██      ██   ███ ██████  ██ ██ ██  ██ ██   ██ ";
	echo " ██  ██  ██   ██ ██      ██    ██ ██   ██ ██ ██  ██ ██ ██   ██ ";
	echo "  ████   ██   ██ ███████  ██████  ██   ██ ██ ██   ████ ██████  ";
	echo "                                                               ";
	echo "                                                               ";
	echo "                ████████ ███████ ███████ ████████              ";
	echo "                   ██    ██      ██         ██                 ";
	echo "                   ██    █████   ███████    ██                 ";
	echo "                   ██    ██           ██    ██                 ";
	echo "                   ██    ███████ ███████    ██                 ";
	echo "                                                               ";
	echo "                                                               ";
else
	echo "    ███    ███ ██ ███    ██ ██ ██████  ████████     ";
	echo "    ████  ████ ██ ████   ██ ██ ██   ██    ██        ";
	echo "    ██ ████ ██ ██ ██ ██  ██ ██ ██████     ██        ";
	echo "    ██  ██  ██ ██ ██  ██ ██ ██ ██   ██    ██        ";
	echo "    ██      ██ ██ ██   ████ ██ ██   ██    ██        ";
	echo "                                                    ";
	echo "                                                    ";
	echo "    ███████ ██████  ██████   ██████  ██████         ";
	echo "    ██      ██   ██ ██   ██ ██    ██ ██   ██        ";
	echo "    █████   ██████  ██████  ██    ██ ██████         ";
	echo "    ██      ██   ██ ██   ██ ██    ██ ██   ██        ";
	echo "    ███████ ██   ██ ██   ██  ██████  ██   ██        ";
	echo "                                                    ";
	echo "                                                    ";
	echo "████████ ███████ ███████ ████████ ███████ ██████    ";
	echo "   ██    ██      ██         ██    ██      ██   ██   ";
	echo "   ██    █████   ███████    ██    █████   ██████    ";
	echo "   ██    ██           ██    ██    ██      ██   ██   ";
	echo "   ██    ███████ ███████    ██    ███████ ██   ██   ";
	echo "                                                    ";
	echo "                                                    ";
fi

for scenelist in ${scene_lists[*]}; do

	printf $LIGHT_BLUE
	echo "************************************************"
	echo "$scenelist test"
	printf "\n$END"

	while read test; do
		((i++))

		printf $YELLOW
		printf "Test %2s: " $i

		if [[ $1 ]]; then
			if [ i == 1 ]; then
				$VALGRIND $MINIRT_PATH 2> ./valgrind_log/test$i
			else
				$VALGRIND $MINIRT_PATH $SCENES_PATH$test 2>./valgrind_log/test$i
			fi
			NO_LEAKS=$(cat ./valgrind_log/test$i | \
			grep "All heap blocks were freed -- no leaks are possible" \
			| cut -d "=" -f5)
			ERROR_OK=$(cat ./valgrind_log/test$i | grep \
			"ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)" \
			| cut -d "=" -f5)
			SEGFAULT=$(cat ./valgrind_log/test$i | grep "SIGSEGV")
			if [ "$SEGFAULT" ]; then
				printf ❌
				printf "$GREY $VALGRIND ./miniRT $SCENES_PATH$test \n$END"
				printf "$RED Segfault\n$END"
			else
				if [ "$NO_LEAKS" ]; then
					if [ "$ERROR_OK" ]; then
						((ok++))
						printf ✅
						printf "$GREY$VALGRIND ./miniRT $SCENES_PATH$test\n$END"
						printf "$GREEN$NO_LEAKS\n$ERROR_OK\n$END"
					else
						printf ❌
						printf "$GREY$VALGRIND ./miniRT $SCENES_PATH$test\n$END"
						printf "$RED check ERROR SUMMARY in valgrind's log\n$END"
					fi
				else
					printf ❌
					printf "$GREY $VALGRIND ./miniRT $SCENES_PATH$test \n$END"
					printf "$RED possible leaks - check valgrind's log\n$END"
				fi
			fi
		else
			if [ i == 1 ]; then
				$MINIRT_PATH 2> ./outfiles/test$i
			else
				$MINIRT_PATH $SCENES_PATH$test 2> ./outfiles/test$i
			fi
			MESSAGE=$(cat ./outfiles/test$i)
			ERROR=$(cat ./outfiles/test$i | grep "Error")
			if [ "$ERROR" ]; then
				((ok++))
				printf ✅
				printf "$GREY ./miniRT $test \n$END"
				printf "error message:\n$MESSAGE\n"
			else
				printf ❌
				printf "$GREY ./miniRT $test \n$END"
				printf "$RED Missing error message\n$END"
			fi
		fi
	done < $scenelist
	printf "\n"
done

printf $PURPLE
printf $BOLD
echo   $ok/$i
printf $END

if [[ "$ok" == "$i" ]]; then
	echo "🥳 🥳 🥳"
	echo "🤩 🤩 🤩"
	echo "🎉 🎉 🎉"
	exit 0
else
	echo "😭 😭 😭"
	exit 1
fi

chmod 660 $NO && rm $NO
