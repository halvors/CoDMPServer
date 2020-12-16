int G_GetClientScore(int clientNum) {
	if (clientNum >= level.maxclients) {
		return 0;
	}

	return level.clients[clientNum].sess.cs.score.score;
}

int G_GetClientRank(int clientNum) {
	if (clientNum >= level.maxclients) {
		return 0;
	}

	return level.clients[clientNum].sess.cs.rank;
}

int G_GetClientTeam(int clientNum) {
	if (clientNum >= level.maxclients) {
		return 0;
	}

	return level.clients[clientNum].sess.cs.team;
}

int G_GetClientPrestige(int clientNum) {
	if (clientNum >= level.maxclients) {
		return 0;
	}

	return level.clients[clientNum].sess.cs.prestige;
}

int G_GetClientKills(int clientNum) {
	if (clientNum >= level.maxclients) {
		return 0;
	}

	return level.clients[clientNum].sess.cs.score.kills;
}

int G_GetClientDeaths(int clientNum) {
	if (clientNum >= level.maxclients) {
		return 0;
	}

	return level.clients[clientNum].sess.cs.score.deaths;
}

int G_GetClientArchiveTime(int clientNum) {
	if (clientNum >= level.maxclients) {
		return 0;
	}

	return level.clients[clientNum].sess.archiveTime;
}

int G_GetClientAssists(int clientNum) {
	if (clientNum >= level.maxclients) {
		return 0;
	}

	return level.clients[clientNum].sess.cs.score.assists;
}
