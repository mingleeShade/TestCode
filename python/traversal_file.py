# 演示如何遍历文件或目录

import sys,os

# 单纯遍历
for path,dir_list,file_list in os.walk("."):
    for file_name in file_list:
        print(os.path.join(path, file_name))

        # 获取文件类型
        print("path[0]:%s"%os.path.splitext(file_name)[0])
        print("path[1]:%s"%os.path.splitext(file_name)[1])
