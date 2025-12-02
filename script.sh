var=$(echo $(seq 5 | shuf)) && ./push_swap $var > tmp.txt && echo $var >> log.txt && cat tmp.txt >> log.txt && cat tmp.txt | wc -l >> log.txt && cat tmp.txt | ./checker_linux $var >> log.txt && echo >> log.txt && cat tmp.txt | wc -l >> justn

# var=$(echo $(seq 497 | shuf) 2147483647 0 -2147483648) 
# && ./push_swap $var > tmp.txt && echo $var >> log.txt 
# && cat tmp.txt >> log.txt && cat tmp.txt | wc -l >> log.txt 
# && cat tmp.txt | ./checker_linux $var >> log.txt 
# && echo >> log.txt && cat tmp.txt | wc -l >> justn

# watch -n 0.1 ./script.sh