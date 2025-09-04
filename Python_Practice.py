from math import *
from typing import List

#print("Hello world!")
#print("C++ is the better langauge this feels so weird!")

#print(2+2)

#character= "john"
#age = 35
#isMale = True

#print("My name is " + character + " and I am ", age, " years old! \n hahahaha new line like C++! ")

#phrase = "I like C++ more. For Real!"
#print(phrase.upper()) #can use built in methods!

#print(len(phrase)) #printing length of string

#print(phrase[0]) #printing by index

#my_num = 10%3
#print("the answer is "+ str(my_num))

#abs(), pow(base, power), max(num1, num2), round()//rounding number up or down

#with from math import *, we can use floor, ceil, sqrt, etc. 

#userName = input("Please enter your name: ") #like C++'s cin>> 
#print("Hello "+ userName) #I really don't like that this is dynamically typed!!!! AHHHHHH

#num1 = input("Please enter the first number: ") #Python by default makes input strings!! need to convert to numbers
#num2 = input("Please enter the second number: ")
#result = float(num1)+float(num2) #typecasting like in c++! //float is helpful for ints and decimals, int is only integers!
#print(result)

#array in Python: #array can be modified. Unlike tuple, which is immutable.
#friends = ["Asli", "Dom", "Yara"] #//Can mix array elements! Don't all have to be ints or strings, etc. 
#friends.append(5) //all typical arary methods work here!
#print(friends[-1]) //printing last element in array
#print(friends[1:]) #this prints every element at index 1 and AFTER!
#print(friends[1:3]) #this prints friends[1] and friends[2]. In list[a:b], a is inclusive and b is not!!!
#other_friends = [1, 2, 3, 4]
#friends.extend(other_friends) #//extend adds the second list onto the first!
#friends.insert(1,"Maryam") #insert(index, entry)
#friends.remove("maryam") //fails because maryam is not in list. can remove existing values!
#friends.clear() #clears the entire list. empty again!
#friends.pop() #//pops the last item off of the list! 
#friends.index("Dom") #returns the index of the value we are looking for
#friends.count("Dom") #returns the number of times the entry "Dom" occurs in the array
#friends.sort() #sorts the list in ascending order!!! Alphabetical for strings
#friends.reverse() #reverses the array! 
#friends2 = friends.copy() #copies the friends list


#tuples in Python: 
#coordinates = (4,5) #tuples are immutable. cannot change or modify!!!
#print(coordinates[0]) #access entry like a list

#Functions in Python, use keyword "def"
#def say_hi(name): #python naming all lower case?
    #print("Hi " + name) #like cout<<. Don't need return statement
#say_hi("Dom")

#def cube(num):
#    return (num*num*num)
#print(cube(3))


#if, elif and else in Python:
#is_male = False
#age = 2
#if is_male and age<=9:
#    print("You are a boy!")
#elif not(is_male) and age<=9: #//use not() for negation
#    print("You are a girl! ")
#elif is_male and age >9:
#    print("You are a man!")
#else:
#    print("You are a woman!")

#def max(num):
#    max = 0
#    for number in num: 
#        if number > max:
#            max = number
#    return max
#data = [0, 2, 5, 19, 100, 9, 1000]
#print(max(data))

'''
def calculate(num1, num2, op):
    if op=="+":
        return num1+num2
    elif op=="-":
        return num1-num2
    elif op=="*":
        return num1*num2
    elif op=="/":
        return num1/num2
num1 = float(input("Enter the first number: ")) #//cout<< "..."; cin>>num1...
op = input("Enter the operator: ")
num2 = float(input("Enter the second number: "))
print(calculate(num1, num2,op))
'''


#Python Dictionary: Hashmap
#monthConversions = { #//this is how you define a dictionary! Curly braces! 
#"Jan":"January", #//key: value pairs. Make sure keys are unique! 
#"Feb": "February",
#"Mar": "March",
#//imagine all the other months here
#}
#print(monthConversions["Feb"]) #//use square brackets and key to access full value! func[key]
#print(monthConversions.get("Hello", "Not a valid key")) #//.get(key, change default response from none to "not a valid key"


#While loop in Python
#i = 1
#while i<=20:
#    print(i)
#    i+=1
#print("Done with loop.")

#secret_word = "Toby"
#guess = input("Enter your guess: ")
#guess_limit = 3
#guess_count = 1
#while guess!= secret_word and guess_count<guess_limit:
#    print("Your guess is wrong! Try again. ")
#    guess_count+=1
#    guess = input("Enter your guess: ")
#if guess_count>=guess_limit:
#    print("Out of guesses!")
#else:
#    print("You win!")


#For loops in Python
#for letter in ("Dominic"):
#    print(letter)

#data = ["Dom", "Asli", "Yara"] #//printing elements of array!
#for name in data:
#    print(name)

#for index in range(10): #//in range(0, 10) means 0-9. Not inclusive 10. In range(inclusive start, not inclusive end)
#   print(index)
##//or: use len(array) for length of array!!!
#for index in range(len(data)):
#    print(data[index])

#Exponent function in Python
#print(2**3) #//same as 2^3
#def raise_to_power(base_num, power):
#    result = 1
#    for index in range(power):
#        result *=base_num
#    return result
#print(raise_to_power(2,3))


#2D arrays and lists in Python
#number_grid=[
#    [1,2,3], 
#    [4,5,6], 
#    [7,8,9],
#    [0] #//every element of the array number_grid is also an array
#]
#print(number_grid[1][2])
#for row in number_grid: #//default is to be done by rows first
#    print(row)
#    for col in row:
#        print(col)


#Try except block in Python
#try:
#    value = 10/0
#    number = int(input("Enter a number: "))
#except ZeroDivisionError: #can specifically catch specific types of errors you are looking for 
#    print("Divided by zero")
#except: #//this catch errors in the try block and throws the except block error. but any and all error would look the same! 
    #not a good practice to just do except! Too broad!
#    print("Invalid input.")


#Reading and writing files in Python
#file = open("test.txt","a") #"r" for read, "w" for write, "r+" for read and write"
#"a" for append #//#include <fstream>, fstream inFile; inFile.open(...);
#print(file.readable())#//prints if the file is readable. if in writing mode then it's false! 
#print(file.read()) #//prints the entire file
#print(file.readline()) #//prints one line of the file
#print(file.readlines()) #//takes the file and puts each line as an entry in a list/array! 
#can use "w" to overwrite the entire file, or write an extirely new file
#file.write("\n I love Asli")
#file.close() #same as C++, close file at the end. inFile.close()

#Modules in Python -- Similar to header files in C++
#import math
#math.methods()
#for external modules, can use pip to install in terminal then import in VS Code!


#Classes and Objects in Python
'''
class Student:
    def __init__(self, name, age, major): #//like the C++ constructor! Student():
        self.name = name
        self.age = age
        self.major = major
    def changeMajor(self,newMajor):
        self.major = newMajor

#from Student import Student #//if we write classes in a different file, we can do from FILENAME import CLASSNAME to use!
Dominic = Student("Dominic", 26, "Computer Science") #can use this like a constructor!
print(Dominic.name)
print(Dominic.age)
print(Dominic.major)
Dominic.changeMajor("Education")
print(Dominic.major)
'''

'''
from Questions import Question
test_questions=[
    "What color are banans?\n a.Yellow \n b.Red \n c.Purple\n ",
    "What color is Toby? \n a. Golden\n b. Grey\n c. Block"
]

test = [
    Question(test_questions[0],"a"),
    Question(test_questions[1],"c")
]

def run_test(test):
    score = 0
    for question in test:
        newanswer = input(question.prompt)
        if newanswer == question.answer:
            print("Good job!")
            score+=1
    print(score)

run_test(test)
'''

#class Student:
#    def __init__(self, name, age, major): #//like the C++ constructor! Student():
#        self.name = name
#        self.age = age
#        self.major = major
#    def changeMajor(self,newMajor):
#        self.major = newMajor
#class freshmen(Student): #//inheritance 
#    def __init__():
#        age = 20

'''
def check_if_palindrome(s:str)->bool:
    left = 0
    right = len(s)-1
    while left<right:
        if(s[left]!=s[right]):
            return False
        left+=1
        right-=1
    return True
'''


#two pointers for reversing string and for squaring elements in sorted array and return sorted result

#sliding window to find size of biggest subarray with sum less than or equal to k
def find_length(nums:list[int],k:int)->int:
    left = ans = curr = 0 #curr is the current sum, ans is the returned answer of how long the max subarray is
    for right in range(len(nums)):
        curr += nums[right]
        right+=1
        while(curr>k):
            curr -= nums[left]
            left+=1
        ans = max(ans, right-left+1)
    return ans

#number of subarrays
def numSubarrayProductLessThanK(self, nums: list[int], k: int) -> int:
        if k <= 1:
            return 0

        ans = left = 0
        curr = 1

        for right in range(len(nums)):
            curr *= nums[right]
            while curr >= k:
                curr //= nums[left]
                left += 1
                
            ans += right - left + 1

        return ans

#fixed size window: 
def find_best_subarray(nums, k):
    curr = 0
    for i in range(k):
        curr += nums[i]
    
    ans = curr
    for i in range(k, len(nums)):
        curr += nums[i] - nums[i - k]
        ans = max(ans, curr)
    
    return ans

#Prefix sum: number of ways to split array
def ways_to_split_array(nums:list[int])-> int:
    prefix = [nums[0]] #//create prefix array and set first element to the first element of nums
    for i in range(1, len(nums)): #//for every element after the first, add the current element to the last element in prefix sum
        prefix.append(nums[i]+prefix[-1]) #prefix[-1] is the sum of all elements up to the last element in prefix!
    ans = 0
    for i in range(len(nums)-1): #can't split the array at last element. So len(nums)-1
        left_section = prefix[i] 
        right_section = prefix[-1]-prefix[i]
        if left_section > right_section:
            ans+=1
    return ans
#More efficient solution!
def waysToSplitArray(self, nums: list[int]) -> int:
        ans = left_section = 0
        total = sum(nums)

        for i in range(len(nums) - 1):
            left_section += nums[i]
            right_section = total - left_section
            if left_section >= right_section:
                ans += 1

        return ans

#hash functions and hash maps in Python
'''
# Declaration: a hash map is declared like any other variable. The syntax is {}
hash_map = {}

# If you want to initialize it with some key value pairs, use the following syntax:
hash_map = {1: 2, 5: 3, 7: 2}

# Checking if a key exists: simply use the `in` keyword
1 in hash_map # True
9 in hash_map # False

# Accessing a value given a key: use square brackets, similar to an array.
hash_map[5] # 3

# Adding or updating a key: use square brackets, similar to an array.
# If the key already exists, the value will be updated
hash_map[5] = 6

# If the key doesn't exist yet, the key value pair will be inserted
hash_map[9] = 15

# Deleting a key: use the del keyword. Key must exist or you will get an error.
del hash_map[9]

# Get size
len(hash_map) # 3

# Get keys: use .keys(). You can iterate over this using a for loop.
keys = hash_map.keys()
for key in keys:
    print(key)

# Get values: use .values(). You can iterate over this using a for loop.
values = hash_map.values()
for val in values:
    print(val)
'''

#Solving two-sum with hashmap:
def twoSum(self, nums: list[int], target: int) -> list[int]:
    dic = {}
    for i in range(len(nums)):
        num = nums[i]
        complement = target - num
        if complement in dic:
            return [dic[complement],i]
        #if complement not in dictionary
        dic[num] = i

#using a set to check first letter to appear twice:
#time complexity is O(N), since we go through everything once. Space complexity is O(1), since O(26) for alphabet = O(1).
#but space complexity could also be O(M), where M is number of allowable characters in the input
def firstRepeatedLetter(self, s: str)-> str:
    seen = set()
    for c in s:
        if c in seen:
            return c
        seen.add(c)

#can pre-process by converting the input array into a set to get rid of duplicates first!
def findNumbers(nums):
    ans = []
    num_set = set(nums) #gets rid of all duplicates 
    for num in num_set:
        if (num-1 not in num_set) and (num+1 not in num_set): #can use keywords like "not in"! 
            ans.append(num)
    return ans

#using hashmap for sliding window, storing key frequencies
#O(k) space given k length substring
from collections import defaultdict

def find_longest_substring(s, k):
    counts = defaultdict(int)
    left = ans = 0
    for right in range(len(s)):
        counts[s[right]] += 1
        while len(counts) > k:
            counts[s[left]] -= 1
            if counts[s[left]] == 0:
                del counts[s[left]]
            left += 1
        
        ans = max(ans, right - left + 1)
    
    return ans

#counting all values in a list and checking their frequencies:
from collections import defaultdict
def areOccurrencesEqual(self, s:str)->bool:
    counts = defaultdict(int)
    for c in s:
        counts[c]+=1
    ans = set(counts.values()) #converts the hashmap frequencies to a set. should only be length 1 if all are the same frequency! 
    return len(ans)==1

'''
#or simply:
from collections import Counter
def areOccurrencesEqual(self, s:str)-> bool:
    return len(set(Counter(s).values())) ==1 #Counter(s) works as same as the hashmap(defaultdict) of all characters in s counts[c]+=1
'''

#earlier, we used prefix sum of subarrays that added to values less than or equal to k.
#now, we need number of subarrays with sum EXACTLY k. We use prefix sum with hashmap! 

#really confusing one: 
# finding number of subarrays with sum of exactly k
from collections import defaultdict

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        counts = defaultdict(int)
        counts[0] = 1
        ans = curr = 0

        for num in nums:
            curr += num
            ans += counts[curr - k]
            counts[curr] += 1
    
        return ans

'''
LinkedList in Python! No Pointers!
'''
class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None

# To add: Let prev_node be the node at position i - 1
def add_node(prev_node, node_to_add):
    node_to_add.next = prev_node.next
    prev_node.next = node_to_add

one = ListNode(1)
two = ListNode(2)
head = one
one.next = two

add_node(one, ListNode(3)) 
while head:
    print(head.val)
    head = head.next

#deleting a node
def delete_node(prev_node):
    prev_node.next = prev_node.next.next

'''
def get_sum(head):
    ans = 0
    dummy = head
    while dummy:
        ans += dummy.val
        dummy = dummy.next
    
    # same as before, but we still have a pointer at the head! Using dummy node to preserve head 
    return ans
'''

#Fast and Slow pointer technique. To find middle element, to detect cycles, etc. 
def get_middle(head):
    slow = head
    fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    
    return slow.val

def find_node(head, k): #finding node k away from the end of the linked list
    slow = head
    fast = head
    for _ in range(k): #start by moving our fast pointer k away from slow. Then just march at same speed
        fast = fast.next
    
    while fast:
        slow = slow.next
        fast = fast.next
    
    return slow

#reversing a linked list: 
def reverse_list(head):
    prev = None
    curr = head
    while curr:
        next_node = curr.next # first, make sure we don't lose the next node
        curr.next = prev      # reverse the direction of the pointer!!
        prev = curr           # set the current node to prev for the next node
        curr = next_node      # move on
        
    return prev


'''
Stack in Python: Use a list! Append() and Pop() 
'''
# Declaration: we will just use a list
stack = []

# Pushing elements:
stack.append(1)
stack.append(2)
stack.append(3)

# Popping elements:
#print(stack.pop()) #would have printed the element to be popped here. 3. 
stack.pop() # 3 

stack.pop() # 2

# Check if empty
not stack # False

# Check element at top
stack[-1] # 1

# Get size
len(stack) # 1

#Matching Parentheses and Brackets Problem: 
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        matching = {"(": ")", "[": "]", "{": "}"}
        
        for c in s:
            if c in matching: # if c is an opening bracket
                stack.append(c)
            else:
                if not stack:
                    return False
                
                previous_opening = stack.pop()
                if matching[previous_opening] != c:
                    return False
 
        return not stack


#deleting adjacent duplicate characters
class Solution:
    def removeDuplicates(self, s: str) -> str:
        stack = []
        for c in s:
            if stack and stack[-1] == c:
                stack.pop()
            else:
                stack.append(c)
        
        return "".join(stack)
    

'''
Queues in Python: Use Deque (Double Ended Queue) from Collections! 
'''
# Declaration: we will use deque from the collections module
import collections
queue = collections.deque()

# If you want to initialize it with some initial values:
queue = collections.deque([1, 2, 3])

# Enqueueing/adding elements:
queue.append(4)
queue.append(5)

# Dequeuing/removing elements:
queue.popleft() # 1
queue.popleft() # 2

# Check element at front of queue (next element to be removed)
queue[0] # 3

# Get size
len(queue) # 3

'''
Monotonic stacks: strictly increasing or strictly decreasing! 
'''
#Monotonic decreasing stack temperature problem: Leetcode 739
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = []
        answer = [0] * len(temperatures)
        
        for i in range(len(temperatures)):
            while stack and temperatures[stack[-1]] < temperatures[i]:
                j = stack.pop()
                answer[j] = i - j
            stack.append(i)
        
        return answer
    
#Leetcode 239: Max in sliding window! First hard problem!
from collections import deque

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        ans = []
        queue = deque()
        for i in range(len(nums)):
            # maintain monotonic decreasing.
            # all elements in the deque smaller than the current one
            # have no chance of being the maximum, so get rid of them
            while queue and nums[i] > nums[queue[-1]]:
                queue.pop()

            queue.append(i)

            # queue[0] is the index of the maximum element.
            # if queue[0] + k == i, then it is outside the window
            if queue[0] + k == i:
                queue.popleft()
            
            # only add to the answer once our window has reached size k
            if i >= k - 1:
                ans.append(nums[queue[0]])

        return ans

#Leetcode 1438: 
from collections import deque

class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        increasing = deque()
        decreasing = deque()
        left = ans = 0
        
        for right in range(len(nums)):
            # maintain the monotonic deques
            while increasing and increasing[-1] > nums[right]:
                increasing.pop()
            while decreasing and decreasing[-1] < nums[right]:
                decreasing.pop()
                
            increasing.append(nums[right])
            decreasing.append(nums[right])
            
            # maintain window property
            while decreasing[0] - increasing[0] > limit:
                if nums[left] == decreasing[0]:
                    decreasing.popleft()
                if nums[left] == increasing[0]:
                    increasing.popleft()
                left += 1
            
            ans = max(ans, right - left + 1)

        return ans

'''
Trees and Graphs in Python for Leetcode. Very similar to C++
'''
class TreeNode:
    def __init__(self, val, left, right):
        self.val = val
        self.left = left
        self.right = right
#DFS: Depth-First Search: going down one branch all the way first!
def dfs(node):#outside class. Inside of class would need self, self.dfs(node.left), etc. 
    if node == None:
        return
    dfs(node.left)
    dfs(node.right)
    return

def preorder_dfs(node):
    if node == None:
        return
    print(node.val)
    preorder_dfs(node.left)
    preorder_dfs(node.right)
    return

def inorder_dfs(node):
    if not node:
        return

    inorder_dfs(node.left)
    print(node.val)
    inorder_dfs(node.right)
    return

def postorder_dfs(node):
    if not node:
        return

    postorder_dfs(node.left)
    postorder_dfs(node.right)
    print(node.val)
    return

#Leetcode 104: Max depth of BST:
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0
        left = self.maxDepth(root.left)
        right = self.maxDepth(root.right)
        return max(left, right)+1
#Iterative solution to the same problem! 
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        
        stack = [(root, 1)]
        ans = 0
        
        while stack:
            node, depth = stack.pop()
            ans = max(ans, depth)
            if node.left:
                stack.append((node.left, depth + 1))
            if node.right:
                stack.append((node.right, depth + 1))
        
        return ans

