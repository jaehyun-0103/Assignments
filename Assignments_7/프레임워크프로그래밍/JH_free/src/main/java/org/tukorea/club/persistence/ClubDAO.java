package org.tukorea.club.persistence;

import java.util.List;
import java.util.Map;

import org.tukorea.club.domain.ClubVO;

public interface ClubDAO {
	public List<ClubVO> list() throws Exception;

	public void add(ClubVO club) throws Exception;

	public List<Map<String, Object>> content(int id) throws Exception;

	public void delete(int id) throws Exception;
}