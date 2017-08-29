poly = list(map(int, input().split()))  # 输入多项式  
if poly[-1]==0:  # 若末项为常数，则将其删除  
    del poly[-2:]  
if poly:  # 若删除末项后还有其他项  
    poly_l = list(range(len(poly)))  # 生成新的列表保存求导后的多项式  
    for i, p in enumerate(poly):  
        if i % 2==0:  # 筛选出所有的系数项  
            poly_l[i] = str(p*poly[i+1])  # 计算求导后的系数  
            poly_l[i+1] = str(poly[i+1] - 1)  # 计算求导后的幂指数  
else:  # 若多项式只有常数项，则输出00  
    poly_l = '00'  
print(' '.join(poly_l).strip())  # 格式化输出字符串  