package org.tukorea.club.service;

import java.util.List;
import java.util.Map;

import org.tukorea.club.domain.ClubVO;
import org.tukorea.club.persistence.ClubDAO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class ClubServiceImpl implements ClubService {
	@Autowired
	private ClubDAO clubDAO;

	public List<ClubVO> readclubList() throws Exception {
		return clubDAO.list();
	}

	public void addClub(ClubVO club) throws Exception {
		clubDAO.add(club);
	}

	public List<Map<String, Object>> readclubContent(int id) throws Exception {
		return clubDAO.content(id);
	}

	public void deleteClub(int id) throws Exception {
		clubDAO.delete(id);
	}
}
