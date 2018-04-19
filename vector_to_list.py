class vector_to_list:
    '''
        Class to process a vector and determine if it should be converted to a list
    '''
    def __init__(self):
        self.insert_beginnig  = 0
        self.insert_end = 0
        self.insert_random_pos = 0
        self.remove_beginnig = 0
        self.remove_end = 0
        self.remove_random_pos = 0
        self.access_beginnig = 0
        self.access_end = 0
        self.access_random_pos = 0
        self.shift_count = 0
        self.resize_count = 0
        self.iteration_count = 0
        self.search_count = 0

    @classmethod
    def incr_insert_beginnig(self):
        self.insert_beginnig =  self.insert_beginnig + 1;


    @classmethod
    def incr_insert_end(self):
        self.insert_end =  self.insert_end + 1;

    @classmethod
    def incr_insert_random_pos(self):
        self.insert_random_pos =  self.insert_random_pos + 1;

    @classmethod
    def incr_insert_beginnig(self):
        self.insert_beginnig =  self.insert_beginnig + 1;


    @classmethod
    def incr_remove_beginnig(self):
        self.remove_beginnig =  self.remove_beginnig + 1;

    @classmethod
    def incr_remove_end(self):
        self.remove_end =  self.remove_end + 1;

    @classmethod
    def incr_access_beginnig(self):
        self.access_beginnig =  self.access_beginnig + 1;

    @classmethod
    def incr_access_end(self):
        self.access_end =  self.access_end + 1;

    @classmethod
    def incr_access_random_pos(self):
        self.access_random_pos =  self.access_random_pos + 1;

    @classmethod
    def incr_shift_count(self):
        self.shift_count =  self.shift_count + 1;

    @classmethod
    def incr_resize_count(self):
        self.resize_count =  self.resize_count + 1;

    @classmethod
    def incr_iteration_count(self):
        self.iteration_count =  self.iteration_count + 1;

    @classmethod
    def incr_search_count(self):                        
        self.search_count =  self.search_count + 1;

    @classmethod
    def show_result(self):
        print("vector is better than list")