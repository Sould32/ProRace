'''
    Script to run with perf (perf script -s excutable.py) to process pt trace information for optimization
'''

data = {}
test = {}

def trace_begin():
    print ("trace begin")


def process_event(param_dict):
    for key in param_dict.keys():
        if key in data:
            data[key].append(param_dict[key])
        else:
            data[key] = param_dict[key]
        test = param_dict
    print (param_dict.keys())

def trace_end():
    print (test)
    print ("trace ends")