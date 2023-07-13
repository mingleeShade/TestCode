import graphviz,random

# 内存占用数据
data = {
    'User': {
        'direct': 20,
        'indirect': [
            ('BackPack', 10),
            ('Hero', 5)
        ]
    },
    'BackPack': {
        'direct': 5,
        'indirect': []
    },
    'Hero': {
        'direct': 10,
        'indirect': [
            ('Weapon', 3),
            ('Armor', 2)
        ]
    },
    'Weapon': {
        'direct': 2,
        'indirect': []
    },
    'Armor': {
        'direct': 2,
        'indirect': []
    }
}

# 初始化图形对象
dot = graphviz.Digraph()

# 添加节点
for k, v in data.items():
    label = '{}\n直接内存：{}KB\n间接内存：{}KB'.format(
        k, v['direct'], sum([x[1] for x in v['indirect']])
    )
    dot.node(k, label)

# 添加边
random.seed()
for k, v in data.items():
    for i in v['indirect']:
        width = random.random() * 2
        dot.edge(k, i[0], label='{}KB'.format(i[1]), penwidth=f'{width}')

# 输出图形文件
dot.render('memory_profile', view=False)
#  dot.render(outfile='pdf')
