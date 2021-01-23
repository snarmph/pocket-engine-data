from json2c import main
import sys

if __name__ == "__main__":
    sys.argv.append("--int-type")
    sys.argv.append("i32")
    sys.argv.append("--float-type")
    sys.argv.append("f32")
    sys.argv.append("--string-type")
    sys.argv.append("string")
    #print(sys.argv)
    main()

