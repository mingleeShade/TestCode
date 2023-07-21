import getopt
import sys

def main(argv):
    input_file = ''
    output_file = ''
    try:
        opts, args = getopt.getopt(argv, "hi:o:", ["input=", "output="])
    except getopt.GetoptError:
        print('usage: python script.py -i <input_file> -o <output_file>')
        sys.exit(2)
    for opt, arg in opts:
        if opt == '-h':
            print('usage: python script.py -i <input_file> -o <output_file>')
            sys.exit()
        elif opt in ("-i", "--input"):
            input_file = arg
        elif opt in ("-o", "--output"):
            output_file = arg
    print('输入文件：', input_file)
    print('输出文件：', output_file)

if __name__ == "__main__":
    main(sys.argv[1:])
