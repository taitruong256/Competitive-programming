class SinhVien:
    def __init__(self, hoten, masv, ketqua):
        self.hoten = hoten
        self.masv = masv
        self.ketqua = ketqua

class Node:
    def __init__(self, sinh_vien):
        self.sinh_vien = sinh_vien
        self.ketqua = sinh_vien.ketqua
        self.next = None

class PriorityQueueLinkedList:
    def __init__(self):
        self.head = None

    def push(self, sinh_vien):
        new_node = Node(sinh_vien)

        if not self.head or sinh_vien.ketqua > self.head.ketqua:
            new_node.next = self.head
            self.head = new_node
        else:
            current = self.head
            # Tìm vị trí để chèn vào danh sách
            while current.next and current.next.ketqua >= sinh_vien.ketqua:
                current = current.next
            new_node.next = current.next
            current.next = new_node

    def pop(self):
        if not self.head:
            return None

        top_node = self.head
        self.head = self.head.next
        return top_node.sinh_vien

    def to_list(self):
        result = []
        current = self.head
        while current:
            result.append(current.sinh_vien)
            current = current.next
        return result

# Thêm vào 5 dữ liệu
priority_queue = PriorityQueueLinkedList()
sinh_vien1 = SinhVien("Nguyen Van A", "SV001", 85)
sinh_vien2 = SinhVien("Tran Thi B", "SV002", 92)
sinh_vien3 = SinhVien("Le Van C", "SV003", 78)
sinh_vien4 = SinhVien("Pham Thi D", "SV004", 95)
sinh_vien5 = SinhVien("Hoang Van E", "SV005", 88)
priority_queue.push(sinh_vien1)
priority_queue.push(sinh_vien2)
priority_queue.push(sinh_vien3)
priority_queue.push(sinh_vien4)
priority_queue.push(sinh_vien5)

# Chuyển danh sách thành list và sắp xếp theo Họ và tên
list_of_students = priority_queue.to_list()
sorted_students = sorted(list_of_students, key=lambda x: x.hoten)

print("Danh sách sinh viên sau khi sắp xếp theo Họ và tên:")
for student in sorted_students:
    print(f"{student.hoten} - Mã SV: {student.masv} - Kết quả: {student.ketqua}")


# In ra 3 sinh viên có Kết quả học tập cao nhất
print("\n3 sinh viên có Kết quả học tập cao nhất:")
for _ in range(3):
    top_student = priority_queue.pop()
    if top_student:
        print(f"{top_student.hoten} - Mã SV: {top_student.masv} - Kết quả: {top_student.ketqua}")
    else:
        print("Không có sinh viên nào trong danh sách.")