# TinySyntaxTree 测试报告

## 测试环境
- 操作系统: Windows
- 编译器: MSVC 19.38
- 构建类型: Release

## 测试结果汇总

| 测试文件 | 结果 |
|---------|------|
| 题目样例1.txt | ✅ 通过 |
| 题目样例2.txt | ✅ 通过 |
| 综合测试1.txt | ✅ 通过 |
| 综合测试2.txt | ✅ 通过 |
| 综合测试3.txt | ✅ 通过 |
| if-stmt.txt | ✅ 通过 |
| for.txt | ✅ 通过 |
| 运算符号.txt | ❌ 失败 |
| 比较符号.txt | ✅ 通过 |
| 位运算.txt | ✅ 通过 |
| +=.txt | ✅ 通过 |
| 正则表达式.txt | ✅ 通过 |
| 嵌套if-else.txt | ✅ 通过 |
| 多语句.txt | ✅ 通过 |
| 三层for循环.txt | ✅ 通过 |
| 复杂表达式.txt | ✅ 通过 |
| repeat语句.txt | ✅ 通过 |

---

## 详细测试结果

### 1. 题目样例1.txt

**输入代码:**
```
{ Sample program
  in TINY language -
  computes factorial
}
read x; { input an integer }
if  (0<x) { don't compute if x <= 0 }
  [for  fact := x downto 1 do 
    fact := fact * x
  enddo;
  write fact]  { output factorial of x }
```

**输出结果:**
```
生成成功！
```

---

### 2. 题目样例2.txt

**输入代码:**
```
{ Sample program
  in TINY language -
  computes factorial
}
read x; { input an integer }

if  (x>0) { don't compute if x <= 0 }
  [fact := 1;
  repeat
    fact := fact * x;
    x := x - 1
  until x = 0;
  write fact  { output factorial of x }]
```

**输出结果:**
```
生成成功！
```

---

### 3. 综合测试1.txt

**输入代码:**
```
{ Sample program
  in TINY language -
  computes factorial
}
{test}
read x; { input an integer }

if (x>0) { don't compute if x <= 0 }
  [fact := 1;
  repeat
    fact := fact * x;
    x := x - 1
  until x = 0;
  write fact  { output factorial of x }
];
  x+=(1+2)*3%4^(fact);
  y::=(a&b&c)#&d?;
  z:= not (123 and 456 ) and 111 or 789 and 123 * 4 +5
```

**输出结果:**
```
生成成功！
```

---

### 4. 综合测试2.txt

**输入代码:**
```
{ Sample program
  in TINY language -
  computes factorial
}
read x; { input an integer }

if  (x>0) { don't compute if x <= 0 }
  [fact := 1;
  repeat
    fact := fact * x;
    x := x - 1
  until x = 0;
  write fact]  { output factorial of x }
else 
  [y::=a#&b?|c&(d)];{test}
for i := 0 to x*5
  do
for j :=3 downto 0
do
     x+=1{这里是两层的for循环}
enddo
enddo
```

**输出结果:**
```
生成成功！
```

---

### 5. 综合测试3.txt

**输入代码:**
```
{预计这是一个很难的测试样例，你准备好了吗}
read xxx;{}
y::=((a&b)#&c)?|d&e#;
z+=not(123)and456 or not(not789);
x:=(5+(((1*2%3^4)))*6^1%7);
if (x<y)[
	if(1)
		[write fact]
	else
		[for i:=0 to x+5
			do
				for j:=0 downto x-5
					do
						y+=1
					enddo;
				haha:=ji{嘿嘿}
			enddo;
		repeat
			true:=false;
			false+=heiheihei
		until x=0]
]
```

**输出结果:**
```
生成成功！
```

---

### 6. if-stmt.txt

**输入代码:**
```
if(1)[write fact];
if(1)[write fact]
else[x:=1]
```

**输出结果:**
```
生成成功！
```

---

### 7. for.txt

**输入代码:**
```
for i:=0 to x+5
  do
    for j:=0 downto x-5
       do
            y+=1
       enddo;
       haha:=ji{嘿嘿}
       enddo;
       repeat
           true:=false;
           false+=heiheihei
       until x=0
```

**输出结果:**
```
生成成功！
```

---

### 8. 运算符号.txt

**输入代码:**
```
x:=(5+(((1*2%3^4)))*6^1%7)
y:= 9*4%2-(8/3+4+4-2-3)+7^2
```

**输出结果:**
```
第 2 行，存在错误： "unexpected token -> ID, name= y"
```

**分析:** 测试用例格式问题，需要添加分号分隔语句。

---

### 9. 比较符号.txt

**输入代码:**
```
a := x<y;
b := x>y;
c := x=y;
d := x<=y;
e := x>=y;
f := x<>y
```

**输出结果:**
```
生成成功！
```

---

### 10. 位运算.txt

**输入代码:**
```
x := not(123)and456 or not(not789);
y := a and (b or c) or (d and e) and not not not f or g
```

**输出结果:**
```
生成成功！
```

---

### 11. +=.txt

**输入代码:**
```
a += 2;
b += a;
c += a + b
```

**输出结果:**
```
生成成功！
```

---

### 12. 正则表达式.txt

**输入代码:**
```
x::=(a&b|c)?&(a&b|c)#;
y::=((a&b)#&c)?|d&e#
```

**输出结果:**
```
生成成功！
```

---

### 13. 嵌套if-else.txt (新增测试用例)

**输入代码:**
```
read x;
if (x=1)
  [write 1]
else
  [if (x=2)
    [write 2]
  else
    [if (x=3)
      [write 3]
    else
      [write 0]]]
```

**输出结果:**
```
生成成功！
```

---

### 14. 多语句.txt (新增测试用例)

**输入代码:**
```
x := 1;
y := 2;
z := 3
```

**输出结果:**
```
生成成功！
```

---

### 15. 三层for循环.txt (新增测试用例)

**输入代码:**
```
for i := 1 to 10
  do
    for j := 1 to 10
      do
        for k := 1 to 10
          do
            x += 1
          enddo
      enddo
  enddo
```

**输出结果:**
```
生成成功！
```

---

### 16. 复杂表达式.txt (新增测试用例)

**输入代码:**
```
x := (1+2)*(3+4)/(5-2)%3;
y := a^b^c;
z := not a and b or c
```

**输出结果:**
```
生成成功！
```

---

### 17. repeat语句.txt (新增测试用例)

**输入代码:**
```
repeat
  x := x + 1;
  y := y - 1
until x = y
```

**输出结果:**
```
生成成功！
```

---

## 测试统计

- 总测试数: 17
- 通过: 16
- 失败: 1
- 通过率: 94.1%

## 新增测试用例说明

本次新增了5个测试用例：

1. **嵌套if-else.txt** - 测试多层嵌套的if-else语句结构
2. **多语句.txt** - 测试多个顺序语句的解析（使用分号分隔）
3. **三层for循环.txt** - 测试三层嵌套的for循环
4. **复杂表达式.txt** - 测试复杂的算术和逻辑表达式
5. **repeat语句.txt** - 测试repeat-until循环结构

## 已知问题

1. **运算符号.txt** 测试失败：该测试用例缺少分号分隔符，导致解析器无法正确识别第二个语句。这是测试用例格式问题，而非解析器bug。
