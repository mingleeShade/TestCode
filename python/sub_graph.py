import graphviz

# 内存占用数据
data = {
    'User1': {
        'direct': 20,
        'indirect': [
            ('BackPack', 10),
            ('Hero', 5)
        ]
    },
    'User2': {
        'direct': 20,
        'indirect': [
            ('BackPack', 10),
            ('Hero', 5)
        ]
    },
    # ...
}

# 初始化图形对象
dot = graphviz.Digraph()

# 添加子图
with dot.subgraph(name='cluster_User') as sg:
    sg.attr(label='User')
    for k, v in data.items():
        if 'User' in k:
            label = '{}\n直接内存：{}KB\n间接内存：{}KB'.format(
                k, v['direct'], sum([x[1] for x in v['indirect']])
            )
            sg.node(k, label)

# 添加节点
for k, v in data.items():
    if 'User' not in k:
        label = '{}\n直接内存：{}KB\n间接内存：{}KB'.format(
            k, v['direct'], sum([x[1] for x in v['indirect']])
        )
        dot.node(k, label)

# 添加边
for k, v in data.items():
    for i in v['indirect']:
        dot.edge(k, i[0], label='{}KB'.format(i[1]))

# 输出图形文件
dot.render('subgraph', view=False)
