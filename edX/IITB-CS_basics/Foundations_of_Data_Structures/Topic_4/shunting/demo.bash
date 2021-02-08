#demo file for simple shunting algorithm using numbers 
shunting=./bin/shunting

make all

echo '-----------------------'
$shunting '1+2'
$shunting '(1+2)*2 - 2/(2-1)'
echo '-----------------------'

make clean
