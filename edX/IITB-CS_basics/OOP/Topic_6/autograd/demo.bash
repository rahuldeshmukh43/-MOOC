#demo file to run autograd
grad=./bin/autograd

make ./Makefile
exp=x*x*x+2*x
echo 'Expr is: ' "$exp"
echo 'gradient is:'
"$grad" "$exp"
