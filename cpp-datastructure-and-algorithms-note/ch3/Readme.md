CH3 渐近记法

时间复杂度： 计算算法执行所需的操作次数，关注循环和递归。
空间复杂度： 计算算法运行时占用的额外内存，关注变量、递归栈帧等。



大O记法
Big-O 表示法： 
big O是函数在逐渐增长率意义上的上限。
是时间复杂度或空间复杂度的表示，用最大项描述增长趋势，忽略常数和低阶项。

1 < logn < n < nlogn < n^2 < n^3 < 2^n > n!

n为实例特征

f(n)=O(g(n)) 读作 “f(n) is big oh of g(n)”
表示g(n)是f(n)的上限

方法：
确定一个最大项以表示复杂度，而且把这个最大项的系数(系数是与变量相乘的数字)设置为1。Identify the largest term to represent the complexity, and set the coefficient of this largest term (the coefficient is the number multiplied by the variable) to 1.



1.	Ω 记法：用于描述一个函数的下界。
记法：f(n)=Ω(g(n)).   g是f的下限
	•	定义：如果存在常数  c > 0  和  n_0 ，使得对于所有  n > n_0 ，都有  f(n) \geq c \cdot g(n) ，则记  f(n) = Ω(g(n)) 。
	•	含义：函数  f(n)  的增长速度不会低于  g(n)  的增长速度。
￼

	2.	θ 记法：
θ表啊是f的上限和下限都是一个函数的情况
用于描述一个函数的精准渐近增长速度。
	•	定义：如果存在常数  c_1, c_2 > 0  和  n_0 ，使得对于所有  n > n_0 ，有  c_1 \cdot g(n) \leq f(n) \leq c_2 \cdot g(n) ，则记  f(n) = θ(g(n)) 。
	•	含义：函数  f(n)  的增长速度和  g(n)  是相同级别的。
￼


	3.	小 o 记法：描述函数  f(n)  增长速度比  g(n)  慢。
	•	定义：如果对于任意正数  c > 0 ，存在  n_0 ，使得对所有  n > n_0 ， f(n) < c \cdot g(n) ，则记  f(n) = o(g(n)) 。
	•	含义： f(n)  的增长速度严格小于  g(n) 。
￼

	•	Ω 表示“至少达到”；
	•	θ 表示“精准等同”；
	•	小 o 表示“严格小于”。


