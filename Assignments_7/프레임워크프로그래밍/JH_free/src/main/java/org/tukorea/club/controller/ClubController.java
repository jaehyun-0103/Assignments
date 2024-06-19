package org.tukorea.club.controller;

import java.util.List;
import java.util.Map;

import org.tukorea.club.domain.ClubVO;
import org.tukorea.club.service.ClubService;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
@RequestMapping(value = "/groups")
public class ClubController {
	private static final Logger logger = LoggerFactory.getLogger(ClubController.class);

	@Autowired
	private ClubService clubService;

	@GetMapping("/list") // 4
	public String listClubGet(Model model) throws Exception {
		List<ClubVO> clubs = clubService.readclubList();
		model.addAttribute("clubs", clubs);
		return "list";
	}

	@GetMapping("/create") // 5
	public String createClubGet() throws Exception {
		return "create";
	}

	@PostMapping("/create") // 6
	public String createClubPost(@ModelAttribute("club") ClubVO vo) throws Exception {
		clubService.addClub(vo);
		return "redirect:/groups/list";
	}

	@GetMapping("/content/{id}") // 7
	public String contentClubGet(@PathVariable int id, Model model) throws Exception {
		List<Map<String, Object>> contents = clubService.readclubContent(id);
		if (contents != null) {
			model.addAttribute("contents", contents);
			return "content";
		} else {
			return "list";
		}
	}

	@GetMapping("/delete/{id}") // 11
	public String deleteClubGet(@PathVariable int id) throws Exception {
		clubService.deleteClub(id);
		return "redirect:/groups/list";
	}
}