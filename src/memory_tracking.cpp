#include <iostream>

#include "models/Box.h"

struct AllocationMetrics {
	uint32_t total_allocated = 0;
	uint32_t total_freed = 0;
	
	uint32_t current_usage() {
		return total_allocated - total_freed;
	}
};

static AllocationMetrics allocation_metrics;

void* operator new(size_t size) {
	allocation_metrics.total_allocated += size;
	std::cout << "Allocating " << size << " bytes" << std::endl;
	return malloc(size);
}

void operator delete(void* memory, size_t size) {
	allocation_metrics.total_freed += size;
	free(memory);
}

static void print_memory_usage() {
	std::cout << "Memory Usage: " << allocation_metrics.current_usage() << " bytes\n";
}

int section_memory_tracking() {

	print_memory_usage();
	std::string string = "Dav";
	print_memory_usage();
	Box* object = new Box;
	print_memory_usage();
	{
		std::unique_ptr<Box> prtr = std::make_unique<Box>();
		print_memory_usage();
	}
	print_memory_usage();
}