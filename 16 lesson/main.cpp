﻿//Timus 1320                                                            +
//  проверить связность графа, если связный то 1, иначе 0
//BFS, DFS должны быть все посещены, если хоть один 0, то 0
//Все вершины записать в set
//Извлекаем из set и идем по used
//Можно через матрицу смежности 1001 * 1001
//2.	 1137
//Два стека, построение эйлерова цикла
//Граф по матрице смежности
//Или массив стеков
//Dfs
//Идем по массиву стека, если есть, то выкинули
//Можно матрицу смежности
//3.	1242                                                            +
//Создать структуру данных
//Надо найти оборотня имя покусанных людей
//Есть отношения родства, 3 предок для 1
//Если есть покусанный, то предок и потомок не могут быть оборотнями
//Идея
//Есть два графа
//Первый граф детей, для каждой вершины смотрим кто внуки правнуки
//Второй граф предков, смотрим детей
//Считываем ребра и создаем два графа сразу, ориентированные
//Считали покусанных
//Для первого делаем dfs по детям потом по потомкам, used один на всех
//Если в конце есть used[I] = 0 то они оборотни
//(можно систему не пересекающихся множеств)
//4.	1069                                                             +
//5.	1129 убрать циклы из графа, есть граф                            +
//Берем первую из нее идем во 2 или 3, тем во вторую

//Граф без циклов, идем и красим двери