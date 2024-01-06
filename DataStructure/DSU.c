int parent[100005]

    void
    init()
{
  for (int i = 0; i < 100005; i++)
    parent[i] = i;
}

int find_root(int x)
{
  if (x == parent[x])
    return x;
  return parent[x] = find_root(parent[x]);
}

bool Same(int a, int b)
{
  return find_root(a) == find_root(b);
}

void Union(int a, int b)
{
  // 將a併進b
  parent[find_root(a)] = find_root(b);
}