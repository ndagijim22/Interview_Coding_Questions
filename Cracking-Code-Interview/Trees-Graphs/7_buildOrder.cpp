/*
    Build Order: you are given a list of projects and a list of dependencies (which is a list
    of pairs of projects, where the second project is dependent on the first project)
    All of a project's dependencies must be build before the project is. Find the order that
    will allow the projects to be built. if there is no valid build order, return an error

    Ex:
    input: 
        projects: a, b, c, d, e, f
        dependencies: (a, b), (f, b), (b, d), (f, a), (d, c)
    output:
        f, e, a, b, d, c

        SOURCE: https://www.geeksforgeeks.org/find-the-ordering-of-tasks-from-given-dependencies/
        WATCH THIS: https://www.youtube.com/watch?v=_BGK0kpE4oE 
        
*/

std::stack<Project*> orderProjects(std::vector<Project*>& projects) {
    std::stack<Project*> stack;
    for (Project* project : projects) {
        if (project->getState() == Project::BLANK) {
            if (!doDFS(project, stack)) {
                return std::stack<Project*>();
            }
        }
    }
    return stack;
}

bool doDFS(Project* project, std::stack<Project*>& stack) {
    if (project->getState() == Project::PARTIAL) {
        return false; // Cycle detected
    }

    if (project->getState() == Project::BLANK) {
        project->setState(Project::PARTIAL);
        std::vector<Project*> children = project->getChildren();
        for (Project* child : children) {
            if (!doDFS(child, stack)) {
                return false;
            }
        }
        project->setState(Project::COMPLETE);
        stack.push(project);
    }
    return true;
}
