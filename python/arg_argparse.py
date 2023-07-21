import argparse

parser = argparse.ArgumentParser(description='命令行参数解析示例')
parser.add_argument('-i', '--input', help='输入文件')
parser.add_argument('-o', '--output', help='输出文件')

args = parser.parse_args()
input_file = args.input
output_file = args.output

print('输入文件：', input_file)
print('输出文件：', output_file)
