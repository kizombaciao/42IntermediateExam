nt		main()
{
	t_node small = {
		.value = 49,
		.right = &(t_node){
			.value = 58,
			.right = &(t_node){.value = 44}
		}
	};
	perimeter(&small);
	printf("\n");

	t_node small2 = {
		.value = 49,
		.right = &(t_node){
			.value = 58,
			.left = &(t_node){.value = 44}
		}
	};
	perimeter(&small2);
	printf("\n");

	t_node small3 = {
		.value = 49,
		.left = &(t_node){
			.value = 58,
			.right = &(t_node){.value = 44}
		}
	};
	perimeter(&small3);
	printf("\n");

	t_node small4 = {
		.value = 49,
		.left = &(t_node){
			.value = 58,
			.left = &(t_node){.value = 44}
		}
	};
	perimeter(&small4);
	printf("\n");
}
