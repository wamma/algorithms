#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int				destination;
	int				weight;
	struct s_node	*next;
}	t_node;

typedef struct s_graph_node
{
	int		vertex;
	t_node	*nodes;
}	t_graph_node;

typedef struct s_graph
{
	int				vertex_count;
	t_graph_node	*nodes;
}	t_graph;

void	add_graph_node(t_graph *graph, int src, int dest, int weight)
{
	t_graph	*graph;

	
}

t_graph	*create_graph(int vertex_count)
{
	t_graph	*graph;
	int		i;

	graph = (t_graph *)malloc(sizeof(t_graph));
	if (!graph)
		return (NULL);
	graph->vertex_count = vertex_count;
	graph->nodes = (t_graph_node *)malloc(sizeof(t_graph_node) * sizeof(t_graph_node));
	if (!graph->nodes)
		return (NULL);
	for (int i = 0; i < vertex_count; i++)
	{
		graph->nodes[i].vertex = i;
		graph->nodes[i].nodes = NULL;
	}
	return (graph);
}

int	main(void)
{
	t_graph		*graph;
	int			vertex_count;

	printf("도시의 개수를 입력하세요: ");
	scanf("%d", &vertex_count);
	graph = create_graph(vertex_count);

	add_graph_node(graph, 0, 1, 4);
	add_graph_node(graph, 0, 2, 2);
}
