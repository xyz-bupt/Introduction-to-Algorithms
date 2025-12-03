# python 用 list 实现栈
def InitStack():
	return []

def StackEmpty(S):
	return len(S) == 0

def Push(S, x, max_size=100):
	if len(S) >= max_size:
		return False
	S.append(x)
	return True

def Pop(S):
	if StackEmpty(S):
		return False, None
	x = S.pop()
	return True, x

def GetTop(S):
	if StackEmpty(S):
		return False, None
	x = S[-1]
	return True, x

def DestroyStack(S):
	S.clear()
	return True

# demo 测试
if __name__ == "__main__":
	S = InitStack()
	print("InitStack:", S)
	print("StackEmpty:", StackEmpty(S))
	print("Push 1:", Push(S, 1, 5))
	print("Push 2:", Push(S, 2, 5))
	print("Push 3:", Push(S, 3, 5))
	print("GetTop:", GetTop(S))
	print("Pop:", Pop(S))
	print("GetTop:", GetTop(S))
	print("DestroyStack:", DestroyStack(S))
	print("Stack after destroy:", S)
