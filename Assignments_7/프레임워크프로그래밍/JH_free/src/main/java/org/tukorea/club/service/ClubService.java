package org.tukorea.club.service;

import java.util.List;
import java.util.Map;

import org.tukorea.club.domain.ClubVO;

public interface ClubService {
	public List<ClubVO> readclubList() throws Exception;

	public void addClub(ClubVO club) throws Exception;

	public List<Map<String, Object>> readclubContent(int id) throws Exception;

	public void deleteClub(int id) throws Exception;
}