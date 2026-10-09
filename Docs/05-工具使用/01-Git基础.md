# Git基础（本地操作）

## 1. 核心结论
Git是分布式版本控制系统，核心是"代码时光机"。本地操作只需掌握三区模型和三步曲：工作区→暂存区→本地仓库，对应命令add→commit→log。

## 2. 为什么需要
- 记录代码每次变更，随时可以回退到历史版本
- 多人协作时合并代码、追溯修改来源
- 找工作时GitHub上的提交记录是能力证明

## 3. 语法与底层原理

### 三区模型
```
工作区（Working Directory）  →  暂存区（Staging Area）  →  本地仓库（Repository）
  你正在编辑的文件                git add 选好的文件          git commit 存的快照
  （git status红色）              （git status绿色）          （git log可见）
```

### 基础命令
| 命令 | 作用 |
|------|------|
| `git init` | 初始化一个新的Git仓库 |
| `git status` | 查看当前状态（哪些文件改了、哪些在暂存区） |
| `git add <文件名>` | 把文件从工作区添加到暂存区 |
| `git add .` | 添加当前目录所有文件 |
| `git commit -m "说明"` | 把暂存区内容提交到本地仓库，形成历史记录 |
| `git log` | 查看提交历史 |

### git status输出解读
- `On branch main`：当前在main分支
- `No commits yet`：还没有任何提交（新仓库）
- `Untracked files:`：未跟踪的文件（红色，Git发现了但还没管理）
- `Changes to be committed:`：已暂存的文件（绿色，准备提交）

## 4. 最小代码示例
```bash
# 1. 进入项目文件夹
cd my-project

# 2. 初始化仓库
git init

# 3. 查看状态（会看到红色的未跟踪文件）
git status

# 4. 添加文件到暂存区
git add README.md
# 或添加所有：git add .

# 5. 查看状态（文件变绿，在"Changes to be committed"下）
git status

# 6. 提交到本地仓库
git commit -m "docs: 初始化README文档"

# 7. 查看历史记录
git log
```

## 5. 嵌入式应用
- 每个里程碑提交一次：环境搭好、LED点亮、传感器调通各一次commit
- 提交信息用规范格式：`feat:`新功能、`fix:`修bug、`docs:`文档
- 每周至少5-8次提交，保持活跃的开发记录

## 6. 常见错误
- 忘记add直接commit：暂存区是空的，会提示"nothing to commit"
- commit信息太随意：写"更新"、"修改"没有意义，要写清改了什么
- 在错误的目录执行git init：会在不该建仓库的地方初始化，删除.git文件夹可撤销

## 7. 自测题
1. `git status` 中红色文件和绿色文件分别代表什么状态？
2. 提交代码的三步曲是什么？每一步的作用是什么？
3. `git add .` 和 `git add README.md` 有什么区别？

## 8. 个人总结
Git本地操作就三件事：看状态（status）、选文件（add）、存快照（commit）。远程仓库、分支、回退等是进阶内容，本地流程走通后再学。

## 9. 参考资料
- Git官方文档：git-scm.com/doc
- 廖雪峰Git教程（中文）
